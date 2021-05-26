function xdot = RoesslerAttractor(x,t) 
% C = variable del actractor, ultimo digito del codigo
% codigo = 13 37 47
global c; 

% x(1) = x, x(2) = y, x(3) = z

  xdot(1) = - x(2) - x(3);
  xdot(2) = x(1) + 0.2*x(2);
  xdot(3) = 0.2 + x(3)*(x(1) - c);

endfunction

