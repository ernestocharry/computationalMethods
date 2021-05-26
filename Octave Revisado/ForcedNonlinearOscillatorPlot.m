global gamma;
global alfa;
global b;
global w;
global F;

fprintf('\n ¡Hola! \n\n En este programa se puede observar el caos existente en un oscilador no linear amortiguado para valores de la magnitud promedio de la fuerza oscilante externa. \n\n Valores de preferencia para la promedio de la fuerza externa oscilante F: 0.2, 0.34875 y 0.42. F debe ser mayor o igual a 0.2 y menor o igual a 0.42 para garantizar coherencia del programa. Introduzca, por favor, el valor F\n\n')


F=input('F = ')

if(F<0.2 | F>0.42) 
	F = 0.42; 
	fprintf('\nValor fuera del intervalo. Valor de F por defecto, 0.42\n')
endif

gamma=0.25;
alfa=-1;
b=1;
w=1;

t = linspace(0,1000,10000000);
x1 = lsode("ForcedNonlinearOscillatorEquation",[0.1 0],t);

figure
plot(t, x1(:,1),'r')
grid on

fprintf('De las gráficas anteriores, pareciese que el movimiento presentase cierta periodicidad; esta periodicidad se traduce en puntos determinado del plano fase (velocidad vs. posición) luego de un periodo = 2*pi (periodicidad de fuerza externa); si el movimiento no presenta caos, se tiene posición-velocidad determinado en el plano fase; si existe caos, no hay una regularidad en los valores. \n\n')

x1f = x1(5000000:2*31416:end,1);
v1f = x1(5000000:2*31416:end,2);

figure
plot(x1f, v1f,'o')

disp('Caos? Fin del programa.')
