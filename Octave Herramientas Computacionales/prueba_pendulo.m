t=linspace(0,40);
x=lsode("pendulo",[179*pi/180 0],t);
plot(t,x,'r','linewidth',3);grid on
