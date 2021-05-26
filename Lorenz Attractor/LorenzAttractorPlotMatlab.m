clear all; 
clc; 

global sigma
global rho
global betta

sigma = 10; 
rho   = 15; 
betta = 8/3; 

t=linspace(0,5,50/0.03); 

x=[]; %Inicialización de la variable

fprintf('LORENZ ATTRACTOR\nEste programa simplemente resuelve la ecuación diferencial que llevan al atractor de Lorenz.\n'); 
rho = input('Por favor, introduzca el valor de rho. \nValores de preferencia para rho: 15,28\n\nRho='); 

[t,x]=ode45('LorenzAttractorMatlab',t, [2 5 5]); 

figure
plot3(x(:,1), x(:,2), x(:,3),'y', 'LineWidth',2)
title('Lorenz Attractor for 0 < t < 50'); 
xlabel('X Axis'); 
ylabel('Y Axis'); 
zlabel('Z Axis'); 
legend('R0 = (2,5,5)'); 
text(2,5,5, 'R01'); 
grid on; 
axis equal; 

figure
subplot(3,1,1)
plot(t, x(:,1),'r')
title('X vs. T')
subplot(3,1,2)
plot(t, x(:,2),'b')
title('Y vs. T')
subplot(3,1,3)
plot(t, x(:,3),'g')
title('Z vs. T')

