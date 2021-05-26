clear all; 
clc; 

% Es necesario crear un arreglo bidimensional, posicion y tiempo
% Longitud L    = 100
% Tiempo máximo = 10
% r = k*DeltaTiempo/DeltaX**2
% Sea k = 1, DeltaX = 0.5, entonces DeltaTiempo = 0.0625
% Numero de puntos en X: 200 puntos en la malla
% Numero de puntos en T: 160 puntos en la malla

L = 1; 
%Tempo = 10; 

dx = 0.5; 

r = 0.25; 

Px = 30; 
Pt = 1000; 

T=zeros(Px,Pt);

x = linspace(0,L,Px);

T(:,1) = sin(pi*x/L);

%
% for i=1:1:Px % Perfil inicial del calor
%	T(i,1) = sin(pi*(i-1)*dx/L); 
% end 
%

tic()
for m=1:Pt-1	
	for j=2:1:Px-1
		T(j,m+1) = T(j,m) + r*(T(j+1,m) - 2*T(j,m) + T(j-1,m)); 
	end
end
toc()

T1 = T(:,1:20:end);
surf(T1)

figure
surfc(T1)

