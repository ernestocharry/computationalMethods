function [xdot]=ForcedNonlinearOscillatorEquation(t,x)

global gamma;
global alfa;
global w;
global b;
global F;

xdot=zeros(2,1); 

xdot(1)=x(2);
xdot(2)=F*cos(w*t)-2*gamma*x(2)-alfa*x(1)-b*x(1)^3;

return