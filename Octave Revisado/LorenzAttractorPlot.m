global sigma
global rho
global betta

t=linspace(0,50,50/0.03); 

sigma = 10; 
rho   = 15; 
betta = 8/3; 

% rho = 28
% x=lsode("LorenzAttractor",[2 5 5],t); 

% plot3(x(:,1), x(:,2), x(:,3),'g', 'linewidth',2)
% title("Lorenz Attractor for 0 < t < 50"); 
% xlabel("X Axis"); 
% ylabel("Y Axis"); 
% zlabel("Z Axis"); 
% legend("R0 = (2,5,5)"); 
% text(2,5,5, "R01"); 

rho = 15; 
x=lsode("LorenzAttractor",[2 5 5],t); 

plot3(x(:,1), x(:,2), x(:,3),'y', 'linewidth',2)
title("Lorenz Attractor for 0 < t < 50"); 
xlabel("X Axis"); 
ylabel("Y Axis"); 
zlabel("Z Axis"); 
legend("R0 = (2,5,5)"); 
text(2,5,5, "R01"); 

figure
subplot(3,1,1)
plot(t, x(:,1),'r')
title("X vs. T")
subplot(3,1,2)
plot(t, x(:,2),'b')
title("Y vs. T")
subplot(3,1,3)
plot(t, x(:,3),'g')
title("Z vs. T")

