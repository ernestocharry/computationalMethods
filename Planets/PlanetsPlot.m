clear all; 
clc; 

fprintf('¡Órbitas de los Planetas!\n');

t=linspace(0,2*pi, 100); 
%Discretizacion o cuantizacion del tempo.
x=[];
Dos = [];
Tres = [];
Vier = [];
Vier2 = [];

[t,x]=ode45('PlanetsEquation',t, [1 0 0 sqrt(2)]); 
%Con condiciones iniciales de x y vy para que trayectoria
%fuese parabola

[t,Dos]=ode45('PlanetsEquation',t,[1 0 0 1]);
%Condiciones iniciales perfectas para trayectoria circular

[t,Tres]=ode45('PlanetsEquation',t, [1 0 0 2]);
%Velocidad inicial en vx = 2 y r =1, tal que la energia es 
%mayor que cero y la trayectoria debe ser hiperbola.

[t,Vier]=ode45('PlanetsEquation',t, [1 0 0 0.5]);
%Velocidad inicial en vx = 0.5 y r =1, tal que la energia 
% sea menor y sea una elipse

tempo = linspace(0,5*pi,100); 

[tempo,Vier2]=ode45('PlanetsEquation',tempo,[1 0 0 1.2]);
%Velocidad inicial en vx = 1.2 y r =1, tal que la energia 
% sea menor y sea una elipse

plot(x(:,1),x(:,2),'mx-','LineWidth',1.5);
grid on;
hold on 
plot(Dos(:,1),Dos(:,2),'ro','linewidth',1.5,'markersize',5);grid on;
plot(Tres(:,1),Tres(:,2),'b','linewidth',1.5,'markersize',5);grid on;
plot(Vier(:,1),Vier(:,2),'y','linewidth',1.5,'markersize',5);grid on;

plot(Vier2(:,1),Vier2(:,2),'k');grid on;

title('Trayectorias del Planeta con centro de fuerza en el origen')
xlabel('X axis')
ylabel('Y axis')
axis square


axis([-5 2 -2 4]) %X min, X max, Y min, Y max
legend('Para*bola','Ci*rculo','Hipe*rbola','Eli*ptica Eins','Eli*ptica Zwei');
legend('boxon')

x1 = x(:,1); 
y1 = x(:,2); 
vx= x(:,3);
vy= x(:,4); 

figure
plot(x1(1:2:end), y1(1:2:end), 'o','MarkerSize',10)

