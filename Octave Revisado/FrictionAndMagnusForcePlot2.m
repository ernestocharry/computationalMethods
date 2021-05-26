global betta 
global alpha

  betta = 0.25;   %Coeficiente de proporcionalidad de la fuerza de Magnus * omega dividido la masa.
  alpha = 0.04;  %Coeficiente proporcioanal a fuerza de friccion divido entre la masa.

  t=linspace(0,20,2000); 

%  v0 = input(' Digite el valor de la velocidad inicial, por favor. ');

%for AnguloVariable=0:5:60
%	x=lsode("FrictionAndMagnusForceEquation",[0 0 v0*cos(AnguloVariable*pi/180) v0*sin(AnguloVariable*pi/180)],t); 
%	plot(x(:,1), x(:,2))
%       axis([0 350 0 350])
%	hold on 
%endfor; 

v01 = 70; 

Xmax = 0;
ThetaMax = 0;  

for AnguloVariable=0:1:60
	x=lsode("FrictionAndMagnusForceEquation",[0 0 v01*cos(AnguloVariable*pi/180) v01*sin(AnguloVariable*pi/180)],t); 
	plot(x(:,1), x(:,2), 'r')
        axis([0 225 0 125])
	axis square
        grid on
	hold on 
	for i=1:1999
		if(x(i,2)*x(1+i,2)<0)
			pos = i; 
			break
		endif
	endfor
	
	if(x(pos,1)>Xmax)
		Xmax = x(pos,1); 
		ThetaMax = AnguloVariable; 
	endif
endfor
	x=lsode("FrictionAndMagnusForceEquation",[0 0 v01*cos(ThetaMax*pi/180) v01*sin(ThetaMax*pi/180)],t); 
	plot(x(:,1), x(:,2), 'b')
        axis([0 225 0 125])
	axis square
        grid on
	hold on 

