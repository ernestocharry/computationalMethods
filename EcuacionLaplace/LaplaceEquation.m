clear all;
clc

% Solucion a la ecuación de Laplace para un potencial dado utilizando el 
% método de sobrerelajación. 

fprintf('\nEcuación de Laplace para potencial con un condensador\n\n')

dx = 0.5; %dx = dy
dy = dx;
X = 30; 
Y = 40; 

Nx = X/dx; %No. de puntos en X
Ny = Y/dy; %No. de puntos en Y

V1 = zeros(X/dx,Y/dy); 

V1(5/dx:25/dx,10/dy)= 100;
V1(5/dx:25/dx,30/dy)=-100; 

figure
surfc(V1)
colorbar()

%Epsilon = input('Digite el valor de control Epsilon\n')
epsilon = 10^(-5);
b = epsilon + 1; 

k=1; 
while b>epsilon
    b=0;
    for i=2:1:Nx-1
        for j=2:1:Ny-1
             if ((j~=10/dy | i<5/dx) | (j~=10/dy | i>25/dx)) &  ((j~=30/dy | i<5/dx) | (j~=30/dy | i>25/dx))
                V2 = (V1(i+1,j) + V1(i-1,j) + V1(i,j+1) + V1(i,j-1))/4;
                a = abs(V2 - V1(i,j));
                V1(i,j) = V2;
                if a>b %Vamos a guardar la maxima diferencia todos los valores
                    b=a;
                end
            end
        end
    end
 b;
 k = k+1; 

end

figure
surfc(V1)
%shading flat
%colorbar()imshow(V1)
colorbar()