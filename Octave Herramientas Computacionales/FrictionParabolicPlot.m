t = linspace(0,5,200); %Time


x=lsode("FrictionParabolicEq",[0 0 5 35],t); 

plot(x(:,1), x(:,2))
axis([0 1 0 5]) 
