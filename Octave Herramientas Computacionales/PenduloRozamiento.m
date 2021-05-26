function xdot = PenduloRozamiento(x, t) 
  k = 0.25; % Coeficiente de amortiguamiento.
  xdot(1) = x(2);
  xdot(2) = -sin(x(1))-k*xdot(1); 
% Suponemos que la fuerza de rozamiento es proporcional a la velocidad
% theta punto. Es como si la punta del pendulo rigido estuviese en su
% punto extremo sobre un carril que tenga un aceite cuyo amortiguamiento 
% fuese proporcional a la velocidad en direccion theta.
endfunction
