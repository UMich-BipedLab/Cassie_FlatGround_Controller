function dqs = getSpringDeflectionRateV2(q4,q5,q6,dq4,dq5,dq6)
dqs = zeros(2,1);
dqs(1) = dq4;
dqs(2) = J_HeelSpringDeflectionEst(q4,q5,q6)*[dq4;dq5;dq6];
end
