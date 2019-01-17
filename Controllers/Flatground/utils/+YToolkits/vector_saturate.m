function u_sat = vector_saturate( u,b1,b2 )
% b1 < = > b2 are all fine, there is no specific lower bound or upper bound 
u_sat = zeros(length(u),1);

for i = 1:length(u)
    u_sat(i) = median([u(i),b1(i),b2(i)]);
end

end

