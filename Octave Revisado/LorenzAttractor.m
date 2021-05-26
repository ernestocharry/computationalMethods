function xdot = LorenzAttractor(x,t) 

% Ecuaciones del atractor de Lorenz

global sigma
global rho
global betta

% x(1) = x, x(2) = y, x(3) = z

  xdot(1) = sigma*(x(2) - x(1));
  xdot(2) = x(1)*(rho - x(3)) - x(2);
  xdot(3) = x(1)*x(2) - betta*x(3);

endfunction

