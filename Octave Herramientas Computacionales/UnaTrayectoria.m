t=linspace(0,6*pi, 100); 
%Discretizacion o cuantizacion del tempo.

x=lsode("PlanetsEquation",[1 0 0 0.9],t); 
plot(x(:,1),x(:,2),'mx-','linewidth',1.5);grid on;
hold on 
xlabel('X axis')
ylabel('Y axis')
axis square

axis([-5 5 -5 5]) %X min, X max, Y min, Y max
A = min(x); 

x1 = x(:,1); 
y1 = x(:,2); 
vx = x(:,3); 
vy = x(:,4); 


%El foco de la elipse se encuentra en el origen de coordenadas

