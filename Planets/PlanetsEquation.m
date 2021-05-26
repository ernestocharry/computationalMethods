function [xdot] = PlanetsEquation(t,x)
xdot=zeros(4,1); 
  xdot(1) = x(3);
  xdot(2) = x(4);
  xdot(3) = - x(1)/((x(1)^2 + x(2)^2)^(3/2));
  xdot(4) = - x(2)/((x(1)^2 + x(2)^2)^(3/2));
return