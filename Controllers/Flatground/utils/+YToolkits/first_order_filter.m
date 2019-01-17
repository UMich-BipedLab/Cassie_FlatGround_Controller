function filtered=first_order_filter(prev,new,para)
filtered=prev*(1-para)+new*para;
end