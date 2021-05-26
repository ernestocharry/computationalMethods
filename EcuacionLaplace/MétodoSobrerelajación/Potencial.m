%Solución ecuación de Laplace utilizando el método de SOBRERELAJACIón
% SOR

clear all; 
clc

fprintf('\nMetodo de Sobrerelajación\n\n'); 
fprintf('Digite, por favor, la longitud horizontal exterior. \nDigite 0 ');
fprintf('para guardar el valor por defecto. Valor por defecto: L1 = 40\n'); 
L1 = input('\nL1 = '); 

fprintf('\nDigite, por favor, la longitud vertical exterior. \nDigite 0 ');
fprintf('para guardar el valor por defecto. Valor por defecto: L2 = 30\n'); 
L2 = input('\nL2 = '); 

if L1 ==0
    L1 = 40;
end

if L2==0
    L2=30;
end

dx = 1; 
dy = dx; 
%dx debe ser igual a dx para aplicar la fórmula. Sólo se define nueva variable para diferenciar.

fprintf('\n\nAhora digite, por favor, LA UBICACIÓN RELATIVA en porcentajes\n');
fprintf('del cuadro interior respecto al cuadro exterior. \n');
fprintf('Primero introduzca el porcentaje mínimo y máximo respecto a L1 \n');
fprintf('Luego el porcentaje mínimo y máximo respecto a L2\n\n');
fprintf('Valores por defecto al introducir todos los valores nulos:\n'); 
fprintf('Desde 30 por ciento hasta 50 por ciento en L1,\n');
fprintf('y desde 20 por ciento hasta 60 por ciento en L2\n\n\n');

Xmin1Porc = input('L1 mínimo porcentual = ');
Xmin2Porc = input('L1 máximo porcentual = ');
Ymin1Porc = input('L2 mínimo porcentual = ');
Ymin2Porc = input('L2 máximo porcentual = ');


%Ubicación relacionada con porcentajes
if Xmin1Porc==0
    Xmin1Porc = 0.3;
else
    Xmin1Porc = Xmin1Porc/100;
end

if Xmin2Porc==0
    Xmin2Porc = 0.5;
else
    Xmin2Porc = Xmin2Porc/100;
end

if Ymin1Porc==0
    Ymin1Porc = 0.2;
else
    Ymin1Porc = Ymin1Porc/100;
end

if Ymin2Porc==0
    Ymin2Porc = 0.6;
else
    Ymin2Porc = Ymin2Porc/100;
end


Xint1 = ceil((L1*Xmin1Porc)/dx); 
Xint2 = ceil((L1*Xmin2Porc)/dx);
Yint1 = ceil((L2*Ymin1Porc)/dy);
Yint2 = ceil((L2*Ymin2Porc)/dy);

Phi = zeros(ceil(L1/dx),ceil(L2/dy)); %X es vertical; Y horizontal.
Phi(Xint1:Xint2,Yint1:Yint2) = 100; 
Phi(1:ceil(L1/dx),1) = 0;



%Ex,Ey = gradient(-V)
%quiver(Ey,Ex, scale=200); 
epsilon = 10^(-5);

 Max=zeros(1,2); %Guarda el valor máximo en el numero de iteraciones y la omega correspondiene
for omega =1:0.01:1.9
     
    k=0;
    b = epsilon+1;
    Phi = zeros(ceil(L1/dx),ceil(L2/dy)); %X es vertical; Y horizontal.
    Phi(Xint1:Xint2,Yint1:Yint2) = 100; 
    
    while b > epsilon
        b = 0;
        for i=2:1:ceil(L1/dx)-1
            for j=2:1:ceil(L2/dy)-1
           % if (PhiInicial(i,j) ==0)
                if ((i<=Xint1 | i>=Xint2)&(j<Yint1 | j>Yint2) | (i>Xint1 | i <Xint1)&(j<Yint1) | (i>Xint1 | i <Xint1)&(j>Yint2) | (j>Yint1 | j<Yint2)&(i<Xint1) | (j>Yint1 | j<Yint2)&(i>Xint2))
                    Ph = (1-omega)*Phi(i,j) + omega*(Phi(i+1,j) + Phi(i-1,j) + Phi(i,j+1) + Phi(i,j-1))/4;
                    a = abs(Ph-Phi(i,j));
                    Phi(i,j) = Ph; 
                    if a>b
                        b = a;
                    end
                end
            end
        end
        k=k+1;
    end
    if Max(1,1)==0
        Max(1,1) = k;
    end
    
    if k<Max(1,1)
        Max(1,1) = k; 
        Max(1,2) = omega;
    end
    Max;
end
fprintf('\n\nEl valor mínimo de interacciones es %d, esta corresponde para un omega de %2.2f\n\n',Max(1,1),Max(1,2));
[Ex,Ey] = gradient(-Phi);

figure
subplot(1,2,1)
surfc(Phi)
colormap('HSV')
colorbar()
%mesh(Phi)

subplot(1,2,2)
contour(Phi)
hold on
quiver(Ex,Ey);  