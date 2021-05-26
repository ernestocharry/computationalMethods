function [xdot] = LorenzAttractorMatlab(t,x) 

% Ecuaciones del atractor de Lorenz

global sigma
global rho
global betta

% x(1) = x, x(2) = y, x(3) = z
 xdot=zeros(3,1); %Inicialización de variable

  xdot(1) = sigma*(x(2) - x(1));
  xdot(2) = x(1)*(rho - x(3)) - x(2);
  xdot(3) = x(1)*x(2) - betta*x(3);

return 

