 classdef GaitLibraryMS <matlab.System & matlab.system.mixin.Propagates & matlab.system.mixin.SampleTime %#codegen
    % Untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.

    % Public, tunable properties
    properties
      
    end

    properties(DiscreteState)

    end

    % Pre-computed constants
    properties(Access = private)
       % gaitparams = struct( 'HAlpha',zeros(10,6),'ct',0);
    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
        end

        function [gaitparams] = stepImpl(obj, gaitLibraryInputs, GaitLibrary_2D)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.
            %cur_speed_x , cur_speed_y, tg_velocity_x, tg_velocity_y, s , t
            
%             gaitLibraryInputs = zeros(26,1);
            gaitparams = PreFunctions.Construct_GLData;
            GL_stanceLeg  = gaitLibraryInputs(1);
            cur_speed_x   = gaitLibraryInputs(2);
            cur_speed_y   = gaitLibraryInputs(3);
            tg_velocity_x = gaitLibraryInputs(4);
            tg_velocity_y = gaitLibraryInputs(5);
            s             = gaitLibraryInputs(6);
            hd_last       = gaitLibraryInputs(7:16);
            dhd_last      = gaitLibraryInputs(17:end);
            
            
            if GL_stanceLeg == 1 % right stance
               LT_2D = GaitLibrary_2D.LT_2D_Right; % size(21,31,15,2);
            else
               LT_2D = GaitLibrary_2D.LT_2D_Left; % size(21,31,15,2); 
            end    
      
            dxr = GaitLibrary_2D.dxo_range'; %31x1
            dyr = GaitLibrary_2D.dyo_range'; %14x1
            
            Sid     = linspace(0,1,21);
            S_cur   = clamp(s,0,1);
            LT_2D_s = interp1(Sid, LT_2D, S_cur);  % size(1,31,15,2);
            LT_2D_s = squeeze(LT_2D_s); % size(31,15,2);
            
            LT_2D_s_x = reshape(LT_2D_s(:,(length(dyr)+1)/2,1),length(dxr),1); % have to make sure these values are monotonic (no crossing each other at zero average vy speed)
            LT_2D_s_y = reshape(LT_2D_s(11,:,2),length(dyr),1);

            %%
            vx_cur = clamp(cur_speed_x,min(LT_2D_s_x),max(LT_2D_s_x));
            vy_cur = clamp(cur_speed_y,min(LT_2D_s_y),max(LT_2D_s_y)); % check this and see if I can use larger boundaries;

            Vsp_x  = interp1(LT_2D_s_x,dxr,vx_cur);
            Vsp_y  = interp1(LT_2D_s_y,dyr,vy_cur);
            
            tg_LT_2D_s_x  = interp1(dxr,LT_2D_s,tg_velocity_x);
            tg_LT_2D_s_x  = squeeze(tg_LT_2D_s_x); % size(15,2);
            tg_LT_2D_s_xy = interp1(dyr,tg_LT_2D_s_x,tg_velocity_y);
            tg_LT_2D_s_xy = squeeze(tg_LT_2D_s_xy); % size(15,2);
            
            des_Vsp_x = tg_LT_2D_s_xy(1);
            des_Vsp_y = tg_LT_2D_s_xy(2);
            
            ct_R = 1/0.4;
            ct_L = 1/0.4;
            
            if GL_stanceLeg == 1
                HAlpha_R = GaitLibrary_2D.RightStance.HAlpha;
                HAlpha_R_dx = interp1(dxr,HAlpha_R,Vsp_x); % 31x14x10x6
                HAlpha_R_dx = squeeze(HAlpha_R_dx); %
                HAlpha_R_dx_dy = interp1(dyr,HAlpha_R_dx,Vsp_y); % 31x14x10x6
                HAlpha_R_Cur = squeeze(HAlpha_R_dx_dy); %
                gaitparams.HAlpha = HAlpha_R_Cur;
                gaitparams.HAlpha(:,1) = hd_last;
%                 gaitparams.HAlpha(:,2) = hd_last + dhd_last/ct_R/5;
                gaitparams.ct = ct_R;
            else
                
                HAlpha_L = GaitLibrary_2D.LeftStance.HAlpha;
                HAlpha_L_dx = interp1(dxr,HAlpha_L,Vsp_x); % 31x14x10x6
                HAlpha_L_dx = squeeze(HAlpha_L_dx); %
                HAlpha_L_dx_dy = interp1(dyr,HAlpha_L_dx,Vsp_y); % 31x14x10x6
                HAlpha_L_Cur = squeeze(HAlpha_L_dx_dy); %
                gaitparams.HAlpha = HAlpha_L_Cur; 
                gaitparams.HAlpha(:,1) = hd_last;
%                 gaitparams.HAlpha(:,2) = hd_last + dhd_last/ct_L/5;
                gaitparams.ct = ct_L;
            end       
            
            gaitparams.Vsp_x = des_Vsp_x;
            gaitparams.Vsp_y = des_Vsp_y;
            gaitparams.GL_stanceLeg = GL_stanceLeg;
        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end
        
%         
%         function [name_1, name_2]  = getInputNamesImpl(~)
%             %GETINPUTNAMESIMPL Return input port names for System block
%             name_1 = 'GLinputs';
%             name_2 = 'GaitLibrary2D';
% 
%         end % getInputNamesImpl
%         
%         function [name_1] = getOutputNamesImpl(~)
%             %GETOUTPUTNAMESIMPL Return output port names for System block
%             name_1 = 'Gaitparams';
% 
%         end % getOutputNamesImpl
        
        % PROPAGATES CLASS METHODS ============================================
        function out = getOutputSizeImpl(~)
            %GETOUTPUTSIZEIMPL Get sizes of output ports.
            out = [1, 1];
        end % getOutputSizeImpl
        
        function out = getOutputDataTypeImpl(~)
            %GETOUTPUTDATATYPEIMPL Get data types of output ports.
            out = 'cassieGLDataBus';
        end % getOutputDataTypeImpl
        
        
        function out = isOutputComplexImpl(~)
            %ISOUTPUTCOMPLEXIMPL Complexity of output ports.
            out = false;
        end % isOutputComplexImpl
        
        function out = isOutputFixedSizeImpl(~)
            %ISOUTPUTFIXEDSIZEIMPL Fixed-size or variable-size output ports.
            out = true;
        end % isOutputFixedSizeImpl        
        
        
        
    end
end
