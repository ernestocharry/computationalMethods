#   Universidad Nacional Autonoma de Mexico
#   Maestria en Ciencias Fisicas
#   Introduccion a Fisia Computacional 
#   Felix Ernesto Charry Pastrana 
#   02-02-2018

#   Transcripcion programa reduccion Gauss-Jordan 
#   para encontrar el vector x que satisface 
#   M x = b
#   dada la matriz M


d = 4   #dimension de la matriz 

M1 = c(1,1,2,2,-1,-2,3,3,3,-7,4,4,3,-2,7,5)
b = c(8,1,10,10)   #vector solucion

M = matrix(M1,nrow=d,byrow=T)

Sol = b # para guardar solucion


M = cbind(M,b)

print(M)

x = seq(1,d,1) #Creado para Barrer

for (p in x) 
  {
  for (i in seq(p,d,1)) 
        {
        if(i==p) 
          {
          a = M[p,p]
          for (j in seq(p,d+1,1)) { M[i,j] = M[i,j]/a } 
          }
        if(i>p)
          {
          a = M[i,p]
          for (j in seq(p,d+1,1)) 
            {
            b = M[p,j] 
            c = M[i,j]
            M[i,j] = c - a*b
            }
          }
        }
}

M2 = M

#Cambiando de matriz triangular superior a inferior 

for (i in x)
{
  for (j in x)
  {
     M2[i,j] = M[d+1-i,d+1-j]
  }
}

for (i in x) { M2[i,d+1] = M[d+1-i,d+1]}

#Volviendo a aplicar el proceso anterior con M2

for (p in x) 
{
  for (i in seq(p,d,1)) 
  {
    if(i==p) 
    {
      a = M2[p,p]
      for (j in seq(p,d+1,1)) { M2[i,j] = M2[i,j]/a } 
    }
    if(i>p)
    {
      a = M2[i,p]
      for (j in seq(p,d+1,1)) 
      {
        b = M2[p,j] 
        c = M2[i,j]
        M2[i,j] = c - a*b
      }
    }
  }
}


for (i in x)
{
  Sol[i] = M2[d+1-i,d+1]
}


print(Sol)