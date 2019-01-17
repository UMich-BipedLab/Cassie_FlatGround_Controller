function u_ramp = ramp( u_begin, u_end,t,tp)

s = min([1,t/tp]);

u_ramp = (1-s)*u_begin + s * u_end;

end

