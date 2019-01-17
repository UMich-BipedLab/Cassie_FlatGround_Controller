function alpha = cutoff_frequency_to_alpha( f,T )
alpha = 1 - exp(-2*pi*f*T);
end

