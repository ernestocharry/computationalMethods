function xdot = pendulo(x, t) 
  xdot(1) = x(2);
  xdot(2) = -sin(x(1));
endfunction
