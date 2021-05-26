clear all; 
close all; 
clc; 

%OSCILADOR ANAMORNICO CU�NTICO
%Primeros diez modos normales
%Para el mi�rcoles a las 11 a.m.
%Graficar una funci�n
fprintf('Realizado por: Ernesto Charry Pastrana\n'); 
fprintf('C�digo: 13 37 47.\n\n'); 
fprintf('�Bienvenido!\n');
fprintf('Ecuaci�n de Schr�dinger unidimensional indep. del tiempo\n\n');
fprintf('Este programa calcula las funciones de onda permitidas\n');
fprintf('para el oscilar arm�nico cu�ntico en un potencial'); 
fprintf('anarm�nico:\n\nV(x) = k x**2 + a**4\n\n');
fprintf('hbar = 1 y m = 1\n\n');
fprintf('Si desea modificar algunos valores, presione\n');
fprintf('0, en caso contrario, si desea utilizar los valores por\n'); 
fprintf('del programa, presione otro n�mero\n\n\n'); 

A = input('Cero (0) para introducir algunos par�metros\n'); 

L = 2; %La longitud positiva
dx = 0.001; 
u=7;
epsilon0 = 0.00001;
%a = 0.05 + u/100; 
a=0;
E0 = 0.3;

if A==0
    fprintf('\n\nPor favor, introduzca los siguiente par�metros\n\n');
    L = input('Digite la longitud L a considerar la ecuaci�n ');
    dx = input('Delta x: discretizaci�n del espacio '); 
    fprintf('�Desea oscilador arm�nico o anarm�nico?\n\n');
    fprintf('Oscilar arm�nico...........................0\n');
    fprintf('Oscilar arm�nico...........................1\n');
    u = input(' ');
    if u==0
        a=0;
    else
        u = input('Digite el �ltimo n�mero de su c�digo\n'); 
        a = 0.05 + u/100;
    end
    epsilon0 = input('Presici�n en la energ�a ');
end

x = linspace(-L,L,ceil(2*L/dx)); %Longitud desde -L hasta L, total 2L 
Phi = zeros(ceil(2*L/dx),1);
Phi(1) = 0.01;
Phi(2) = 0.2;
V = (x.^2)/2 + a*x.^4;

fprintf('\n�Desea animaci�n?\n Si = 0, No = cualquier n�mero\n');
Anime = input('');

figure(1)
plot(x,V)
title('Potencial');
axis([-L L -8*L 8*L])

PhiAnterior = 1; 
b=1; 

E1 = 0;

tic()
for j=1:1:7000
    E = E0 + (j-1)*0.01;
 
    for i = 2:1:ceil(2*L/dx)-1
        Phi(i+1) = 2*Phi(i) - Phi(i-1) + 2*(dx^2)*( (x(i)^2)/2 + a*(x(i))^4 - E )*Phi(i);
        Phi(i+1);
    end
    
    if PhiAnterior*Phi(ceil(2*L/dx)) < 0
       
        PhiAnteriorI = PhiAnterior; 
        PhiSiguiente = Phi(ceil(2*L/dx));
        PhiAnterior=Phi(ceil(2*L/dx));
        Dif = abs(PhiSiguiente - PhiAnteriorI);
        
        N = 1; 
        
        ESig = E0 + (j-1)*0.01;
        EAnt = E0 + (j-2)*0.01;
        
       
        
        while Dif > epsilon0 & N<50
            E = (ESig + EAnt)/2;
            
            for i = 2:1:ceil(2*L/dx)-1
                Phi(i+1) = 2*Phi(i) - Phi(i-1) + 2*(dx^2)*( (x(i)^2)/2 + a*(x(i))^4 - E )*Phi(i);
                Phi(i+1);
            end
            
            
            
            if PhiAnteriorI<0
                if Phi(ceil(2*L/dx)) < 0
                    PhiAnteriorI = Phi(ceil(2*L/dx)); 
                    EAnt = E;
                else
                   PhiSiguiente =  Phi(ceil(2*L/dx)); 
                   ESig = E; 
                end
            else
                if Phi(ceil(2*L/dx)) < 0
                    PhiSiguiente =  Phi(ceil(2*L/dx)); 
                    ESig = E; 
                else
                    PhiAnteriorI = Phi(ceil(2*L/dx)); 
                    EAnt = E;
                end
            end
            
            Dif=abs(ESig - EAnt);
            N = N+1;
        end 
        
        
        fprintf('\n%d) El valor de energ�a es %f', b, E)
        
        %Para graficar las primeras cuatro energ�as. 
        if b<5
            b;
            figure(2)
            subplot(2,2,b)
            plot(x,Phi,'m*')
            str = num2str(E);
            str = ['Valor de Energia: ',str];
            title(str);
            
            figure(4)
            hold on
            if b==1
                plot(x,Phi,'r*')
            elseif b==2
                plot(x,Phi,'y*')
            elseif b==3
                plot(x,Phi,'g*')
            else
               plot(x,Phi,'c*')
            end
            
            title('Cuatro primeras autofunciones');
            grid on
        end
   
        
        b=b+1;
        DeltaE = E - E1;
        fprintf('\nDelta E %f\n',DeltaE);
        E1 = E;
        
    end
    
    if Anime==0
        figure(3)
        plot(x,Phi,'r'), 
        axis([-L L -80*L 80*L])
        title('Funcion de Onda')
        xlabel('x')
        ylabel('Alt')
        F(j)=getframe;
    end
end
fprintf('\n\n');
toc()