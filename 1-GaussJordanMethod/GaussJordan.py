# Universidad Nacional Autonoma de Mexico
# Posgrado en Ciencias Fisicas
# Introduccion a Fisica Computacional
# Profesor: Santiago Caballero
# Autor: Felix Ernesto Charry Pastrana
# 01.02.2018
#
#----------------------------------------------
#   Solucion de sistemas de ecuaciones
#   utilizando Gauss-Jordan
#   Sistema a solucionar: M * x = b
#----------------------------------------------
#
import numpy as np
print "\n Gauss-Jordan method"
print "\n Estudiante: Ernesto Charry Pastrana"

n = 5;  # Orden del sistema

M = np.array([[5.0,4.0,-1.0,2.0,-9.0,29.0],[4.0,3.0,-5.0,-5.0,4.0,-65.0],[6.0,-6.0,-3.0,-9.0,4.0,-113.0],[-8.0,8.0,5.0,-3.0,-6.0,35.0],[-3.0,-7.0,2.0,-5.0,4.0,-50.0]])
        # M es la matrix aumentada del sistema.
        # por eso el orden es n+1.
        # Es necesario ingresar los datos con .0
        # para que los datos no sean tipo entero. Ej: 7.0 = 7
M2 = np.zeros((n,n+1))
X = np.zeros(n)

print "\n Matrix Aumentada del sistema a solucionar: \n"
print M
print "\n"

#   Convirtiendo matriz M en triangular superior.
#   p barre sobre la diagonal.
for p in range(0,n-1):
    for i in range(p,n):
        if(i==p):   # Normalizando la fila
            v = M[i,i]
            for j in range(p,n+1):
                M[i,j] = M[i,j]/v
    
        if(i>p):
            # Multiplicando la fila normalizada
            # por el primer elemento de la fila para
            # despues restar y reemplazarla
            a = M[i,p]
            for jj in range(p,n+1):
                b = M[i,jj]
                c = M[p,jj]
                M[i,jj] = b - a*c
                
print " Matriz trigangular superior"
print M
print "\n"

# Escribiendo la matriz triangular superior M en
# matriz triangular inferior M2.

for iii in range(0,n):
    M2[iii,n] = M[n-1-iii,n]
    for jjj in range(0,n):
        M2[iii,jjj] = M[n-1-iii,n-1-jjj]


print " Matriz trigangular inferior"
print M2
print "\n"


# Mismo procedimiento anterior
for p in range(0,n-1):
    for i in range(p,n):
        if(i==p):
            v = M2[i,i]
            for j in range(p,n+1):
                M2[i,j] = M2[i,j]/v
    
        if(i>p):
            a = M2[i,p]
            for jj in range(p,n+1):
                b = M2[i,jj]
                c = M2[p,jj]
                M2[i,jj] = b - a*c

print " Resultados\n "
print M2
print "\n"


for iii in range(n-1,-1,-1):
    print  "Variable No. ", n-iii, "  =  ", M2[iii,n]

print "\n"
