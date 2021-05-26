function xdot=ForcedNonlinearOscillatorEquation(x,t)

global gamma;
global alfa;
global w;
global b;
global F;

xdot(1)=x(2);
xdot(2)=F*cos(w*t)-2*gamma*x(2)-alfa*x(1)-b*x(1)^3;
endfunction
