clear all;
%clc; 

R = 10; 
t = 800; 

dr = 0.5;  %0.2
dt = 0.5; % 0.1
k = 0.027; 

gamma = k*dt/(dr^2); % debe ser mayor que 0.05


T =  zeros(R/dr, t/dt); 

T(:,1) = 20; 
T(R/dr,:) = 350; 

Tr = zeros(R/dr,1); 
Tr = T(:,1); 
tempo = linspace(1,R,R/dr); 


tic()
for i=1:1:t/dt %
    for m=1:1:R/dr - 1 % PosiciÛn
        if m==1
            T(m,i+1) = T(m,i) + 6*gamma*(T(m+1,i) - T(m,i));
        else
            T(m,i+1) = T(m,i) + gamma*( (T(m+1,i) - T(m-1,i))/m + T(m+1,i)+T(m-1,i)-2*T(m,i));
        end    
    end
    
    if mod(i,5)==0 %Grafica da que i es 5
        Tr = T(:,i+1);
        plot(tempo,Tr,'*'), axis([1 10 0 400])
        title('Temperatura contra Tiempo para Pollo Esférico')
        xlabel('tiempo')
        ylabel('Temperatura [ºC]')
        F(i)=getframe;
        
    end
    
    if T(1,i+1) > 150
        fprintf('El valor del tiempo requerido es'), i*dt
        break; 
    end
end 
toc()

figure
surfc(T)
shading flat
colorbar()