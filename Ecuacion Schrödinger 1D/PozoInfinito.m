clear all; 
clc; 
close all; 

fprintf('\nBienvenido\n\n');
fprintf('Realizado por: Félix Ernesto Charry Pastrana. \n');
fprintf('Fecha: 19.06.2013. Herramientas computacionales.\n\n');
fprintf('Este programa calcula los autovalores de energia en la \n');
fprintf('ecuación de Schroedinger para un pozo de potencial muy \n');
fprintf('grande, V=100. Idealmente es infinito\n\nDigite, por favor,\n');
fprintf('0 si desea encontrar las energias correspondientes a \n');
fprintf('funciones de onda PAR o \n1 si desea conocer las energias \n');
fprintf('correspondientes a funciones de onda IMPAR\n\n\n');

a = input('Digite 0=Par o 1=Impar\n');

L = 2; %Sólo nos intereza de L=0 hasta L=1
dx = 0.01; 
Vmax = 100;

x = linspace(0,L,ceil(L/dx)); 
Phi = zeros(1,ceil(L/dx));
V = Vmax*ones(1, ceil(L/dx)); 
V(1:ceil(1/dx))=0; %Zona permitada L de 0 hasta 1.  


E = 1.125; 

if a==0 
    Phi(1) = 1;
    Ymin = -2;
    Ymax = 2;
else
    Phi(1) = 0;
    Ymin = -60;
    Ymax = 60;
end
Phi(2) = 1; 

fprintf('\nSe barreran valores de energia desde E = 1 hasta \n');
fprintf('E = 5000*0.05+1 = 251\n\n'); 

fprintf('¿Desea ver animación? Digite 1 si sí o 0 si no.\n');
fprintf('El programa puede demorarse debido a la animación\n');
b = input('\n'); 

PhiAnterior = 1; 
E0 = 1;
a=1;
 
fprintf('\nAutovalores de energía \n\n');
tic()
for j=1:1:5000
    
    for i=2:1:ceil(L/dx)-1
        Phi(i+1) = 2*(dx^2)*(V(i) - E0*(1+j*0.05))*Phi(i) + 2*Phi(i) - Phi(i-1);
    end
    
    if PhiAnterior*Phi(ceil(L/dx))<0
        fprintf('%d) El valor de la energía es %.2f \n', a, E0*(1+j*0.05));
        a=a+1;
    end
    
    PhiAnterior = Phi(ceil(L/dx));
    
    if b==1
        plot(x,Phi), axis([0 2 Ymin Ymax])
        title('Funcion de Onda')
        xlabel('tiempo')
        ylabel('Temperatura [ºC]')
        F(j)=getframe;
    end   
    
  
end
fprintf('\n');
toc()
fprintf('\n');