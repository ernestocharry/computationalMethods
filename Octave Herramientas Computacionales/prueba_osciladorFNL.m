global gamma;
global alfa;
global b;
global w;
global F;
hold off;
gamma=0.25;
alfa=-1;
b=1;
w=1;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%F=0.2;
%F=0.34875;
F=0.42;
t=linspace(0,1000,10000000);
x=lsode("oscilador_forzado_no_lineal",[0.1 0],t);
xf=x(5000000:2*31415:end,1);
vf=x(5000000:2*31415:end,2);
plot(xf,vf,'o');
