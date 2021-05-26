function xdot = FrictionParabolicEq(x,t) 

  alpha = 1; %Coeficiente de prop de la fuerza
  masa = 1;  % masa en kilogramos
  g = 10;   %gravity
  
  xdot(1) = x(3);
  xdot(2) = x(4);
  xdot(3) = - (alpha*sqrt(x(3)**2+ x(4)**2)*x(3))/masa;
  xdot(4) = - (alpha*sqrt(x(3)**2+ x(4)**2)*x(4))/masa - g;
endfunction
