t=linspace(0,10,100);

x=lsode("MagnusForceEquation",[0 0 1 -10],t); 

plot(x(:,1), x(:,2))
axis([0 10 -10 10])
grid on

