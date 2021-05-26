function xdot = MagnusForceEquation(x,t) 

% Simulacion movimiento debido a rotacion de balon y trasnlacion del mismo en un fluido

  betta = 1;   %Coeficiente de prop de la fuerza
  masa = 1;    % masa en kilogramos
  omega = 10;  %Velocidad angular en direccion z

  
  xdot(1) = x(3);
  xdot(2) = x(4);
  xdot(3) = - (betta*omega*x(4))/masa;
  xdot(4) =   (betta*omega*x(3))/masa;
endfunction
