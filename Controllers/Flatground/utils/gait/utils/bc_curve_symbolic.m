function [ alpha,b,s ] = VirtualConstraints_Bezier( M )
syms s
alpha = sym('a', [1,M+1]);
b = sym(zeros(1,1));

for k=0:M
    b = b + alpha(k+1) * (factorial(M)/(factorial(k)*factorial(M-k))) * s^k * (1-s)^(M-k);
end

