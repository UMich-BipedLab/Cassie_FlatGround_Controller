for i = 1:6
figure(i)
clf;
Vx = reshape(LT_2D_Right(16,:,:,1),31,14);
Vy = reshape(LT_2D_Right(16,:,:,2),31,14);
a11 = reshape(GaitLibrary_output.RightStance.HAlpha(:,:,1,i),31,14);
surface(Vx,Vy,a11)
xlabel('vx')
ylabel('vy')
zlabel('bezier')
end