clear all;
clc

global gamma; 
global alfa; 
global b; 
global w; 
global F; 

gamma = 0.25;
alfa = -1; 
b=1; 
w=1; 

fprintf('¡Hola!\n\nEn este programa se puede observar el caos \n')
fprintf('existente en un oscilador no linear amortiguado para \n')
fprintf('valores de la magnitud promedio de la fuerza oscilante \n')
fprintf('externa\n\nValores de preferencia para F externa: 0.2, \n')
fprintf('0.34875 y 0.42. F debe ser mayor o igual a 0.2 y menor \n')
fprintf('o igual a 0.42 para garantizar coherencia del \n')
fprintf('programa.\nIntoduzca, por favor, el valor de F.\n\n')

F=input('F= ');

if F<0.2 | F>0.45
        F=0.42; 
        fprintf('\nValor fuera del intervalo. Valor por defecto')
        fprintf(' F = 0.42\n')
end

x=[]; %Inicialización de la variable

t=linspace(0,1000,10000000); 
[t,x] = ode45('ForcedNonlinearOscillatorEquation', t, [0.1 0]); 

%figure
%plot(t,x(:,1),'r')
%grid on

fprintf('\n\nDe las gráficas anteriores, pareciese que el \n')
fprintf('movimiento presentase cierta periodicidad; esta \n')
fprintf('periodicidad se traduce en puntos determinado del \n')
fprintf('plano fase (velocidad vs. posición) luego de un \n')
fprintf('periodo = 2*pi (periodicidad de fuerza externa); \n')
fprintf('si el movimiento no presenta caos, se tiene \n'); 
fprintf('posición-velocidad determinado en el plano fase; si \n')
fprintf('existe caos, no hay una regularidad en los valores. \n\n')

xf = x(5000000:2*31416:end,1);
vf = x(5000000:2*31416:end,2);

figure
plot(xf, vf,'o')

disp('¿Caos? Fin del programa.')