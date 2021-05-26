global betta 
global alpha

  betta = 0.25;   %Coeficiente de proporcionalidad de la fuerza de Magnus * omega dividido la masa.
  alpha = 0.04;  %Coeficiente proporcioanal a fuerza de friccion divido entre la masa.

  theta = 9;  %Angulo de salida en grados, es necesario pasarlo a radianes 
  v0 = 70;     %Velocidad inicial, en m/s

  t=linspace(0,20,200); 


%x=lsode("FrictionAndMagnusForceEquation",[0 0 v0*cos(theta*pi/180) v0*sin(theta*pi/180)],t); 
%plot(x(:,1), x(:,2))
axis([0 300 0 150])
grid on

v0 = input(' Digite el valor de la velocidad inicial, por favor. ');

for AnguloVariable=0:5:60
	x=lsode("FrictionAndMagnusForceEquation",[0 0 v0*cos(AnguloVariable*pi/180) v0*sin(AnguloVariable*pi/180)],t); 
	plot(x(:,1), x(:,2))
        axis([0 500 0 300])
	hold on 
endfor; 



v01 = 100; %Comparativo
for AnguloVariable=0:5:60
	x=lsode("FrictionAndMagnusForceEquation",[0 0 v01*cos(AnguloVariable*pi/180) v01*sin(AnguloVariable*pi/180)],t); 
	plot(x(:,1), x(:,2), 'r')
        axis([0 500 0 300])
	axis square
        grid on
	hold on
endfor; 


