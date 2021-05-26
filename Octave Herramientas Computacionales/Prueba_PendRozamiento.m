t=linspace(0,40);
x=lsode("PenduloRozamiento",[179*pi/180 0],t);
plot(t,x(:,1),'mx-','linewidth',1.5);grid on;
hold on
plot(t,x(:,2),'bd-','linewidth',1.5);grid on;

