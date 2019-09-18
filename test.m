clear T1 T2

T1 = reshape(GaitLibrary_output.RightStance(42,12,:),10,6);


T2 = zeros(60,1);

for i = 1:60
   
T2(i) = interp2(xo_range,dxo_range, GaitLibrary_output.RightStance(:,:,i),xo_range(42),dxo_range(12));    
    
end    

T2 = reshape(T2, 10,6);