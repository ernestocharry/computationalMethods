function [xdot] = FrictionAndMagnusForceEquation(t,x)

global betta;
global alpha;

% Programa que calcular la trayectoria de una esfera rugosa debido al movimiento de friccion 
% y a la fuerza de Magnus. 

xdot = zeros(4,1); 

  g = 9.8; 

  v = sqrt(x(3)^2+x(4)^2); 	%Magnitud de la velocidad necesaria para velocidad de friction

  if(v<14)			%Para bola rugosa 
	coef = 0.5; 
  else
	coef = (0.5*14)/(v+eps);
  end 

  xdot(1) = x(3);
  xdot(2) = x(4);
  xdot(3) = - alpha*coef*v*x(3) - betta*x(4);
  xdot(4) = - alpha*coef*v*x(4) + betta*x(3) - g; 

return
