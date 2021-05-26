clear all; 
clc; 

fprintf('Bienvenido. Atractor de Roessler\n')
t=linspace(0,50,50/0.03); 

global c; 

c = input('Digite, por favor, el ultimo digito de su codigo ');

x=[];

[t,x]=ode45('RoesslerAttractorEquation',t,[-1 0 0]); 

figure
plot3(x(:,1), x(:,2), x(:,3),'y', 'LineWidth',2)
title('Roessler Attractor for 0 < t < 50'); 
xlabel('X Axis'); 
ylabel('Y Axis'); 
zlabel('Z Axis'); 
legend('R0 = (2,5,5)'); 
text(-1,0,0, 'R0'); 
axis square
grid on

figure
subplot(3,1,1)
plot(t, x(:,1),'r')
grid on
title('X vs. t')
subplot(3,1,2)
plot(t, x(:,2),'b')
grid on
title('Y vs. t')
subplot(3,1,3)
plot(t, x(:,3),'g')
grid on
title('Z vs. t')

