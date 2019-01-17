function varargout = getCompiledPortWidths(mdl,writeFun)
    % GETCOMPILEDPORTWIDTS creates a function to return port names and
    % sizes for a Simulink model.
    %
    
    if nargin<2
        writeFun = 1;
    end
    
    % find_system expects a handle to a model and returns a vector of handles
    % to refer to the blocks found.
    sys = get_param(mdl, 'Handle');
    Outports = find_system(sys,'SearchDepth',1,'BlockType','Outport');
    
    w = zeros(size(Outports));
    
    try
        fprintf('\n');
        fprintf('Compiling %s to determine port widths....\n',mdl);
        f=str2func(mdl);
        f([],[],[],'compile');
        for k=1:length(Outports)
            pw = get_param(Outports(k),'CompiledPortWidths');
            if ~isempty(pw)
                w(k) = pw.Inport;
            else
                w(k) = -1;
            end
        end
        f([],[],[],'term');
        fprintf('\tcomplete.\n');
    catch err
        warning('Could not compile the model to determine the port widths!');
        rethrow(err);
    end
    
    if writeFun
        %fprintf('Writing %s_compiledPortWidths.m ....\n', mdl);
        fid = fopen([mdl '_compiledPortWidths.m'],'w');
        fprintf(fid, 'function p = %s()\n', [mdl '_compiledPortWidths']);
        fprintf(fid, '\tp = struct(''PortName'',cell(%d,%d),''PortWidth'',-1);\n', size(w));
        for k=1:numel(w)
            OutportName = get_param(Outports(k), 'Name');
            fprintf(fid, '\n\t%% PortName: %s\n', OutportName);
            fprintf(fid, '\tp(%d).PortName = ''%s'';\n', k, OutportName);
            fprintf(fid, '\tp(%d).PortWidth = %d;\n', k, w(k));
        end
        fprintf(fid, 'end\n');
        fclose(fid);
        %fprintf('\tcomplete.\n');
    end
    if nargout>0
        varargout{1} = w;
        if nargout>1
            varargout{2} = [mdl '_compiledPortWidths'];
        end
    else
        varargout = {};
    end
end
