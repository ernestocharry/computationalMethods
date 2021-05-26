//  Universidad Nacional Autonoma de Colombia
//  Posgrado en Ciencias Fisicas
//  Introduccion a la Fisica Computacional
//  Profesor: Santiago Caballero
//  Autor: F. E. Charry-Pastrana
//  11.02.2017

//  Proceso L U para resolver sistemas lineales
//  M x = b.
//  El tamano de M es nxn

//  Programa valido para sistemas 3x3
#include <iostream>
using namespace std;

void PrintMatrix(float M[3][3]);

int main()
{
    cout<<"\n\nSolucion sistemas lineales ";
    cout<<"3x3\nutilizando metodo L U\n\n";
    
    //  Declaracion variables
    int i, j, k, p;
    float x,y,z,l;
    float M[3][3],L[3][3], U[3][3];
    float b[3];
    float SolX[3], SolY[3];
    
    int n = 3;      // tamano matriz
    float C = 0;    // Utilizado en solucion Lower y Upper
    
    //  Valores matriz M y vectores b iniciales
    M[0][0] = 1;
    M[0][1] = 2;
    M[0][2] = 3;
    M[1][0] = -1;
    M[1][1] = 0;
    M[1][2] = 1;
    M[2][0] = 3;
    M[2][1] = 1;
    M[2][2] = 3;
    b[0] = -5;
    b[1] = -3;
    b[2] = -3;
    
    //  Copiando matriz original en L
    //  Inicializando SolX, SolY y U en ceros
    for (i=0;i<n;i++)
    {
        SolX[i] = 0;
        SolY[i] = 0;
        for (j=0;j<n;j++)
        {
            L[i][j]=0;
            U[i][j]=M[i][j];
        }
    }
    
    cout<<"\nMatrix inicial:\n\n";
    PrintMatrix(U);
    
    
    for (int p=0;p<n;p++)
    {
        
        for (i=p;i<n;i++)
        {
            if(i==p)
            {
                x = U[i][p];
                L[p][p] = x;
                for(j=0;j<3;j++)
                {
                    U[i][j] = U[i][j]/x;
                }
            }
            if(i>p)
            {
                y = U[i][p];
                L[i][p] = y;
                for(j=0;j<n;j++)
                {
                    z = U[i][j];
                    l = U[p][j];
                    U[i][j] = z - y*l;
                }
                
            }
        
        }
    }
    
    cout<<"\nMatrix upper:\n\n";
    PrintMatrix(U);
    cout<<"\nMatrix lower:\n\n";
    PrintMatrix(L);

    // Resolver el sistema L*SolY = b
    for(i=0;i<3;i++)
    {
        for(j=0; j<i; j++)
        {
            C= L[i][j]*SolY[j] + C;
        }
        SolY[i] = (b[i] - C)/L[i][i];
        C = 0;
    }
    
    // Mostrando solucion parcial: SolY
    for(i = 0; i<3; i++)
    {
        cout << "\nSolucion Parcial i, SolY[i]: " <<i<<"; "<<SolY[i];
    }
    
    // Resolver el sistema U*SolX = SolY
    for(i=0; i<3; i++)
    {
        for(j=(3-i); j<3; j++)
        {
            C= U[2-i][j]*SolX[j] + C;
        }
        SolX[2-i] = (SolY[2-i] - C)/U[2-i][2-i];
        C = 0;
    }
    cout<<"\n\n";
    // Mostrando solucion parcial: SolX
    for(i = 0; i<3; i++)
    {
        cout << "\nSolucion Final i, SolX[i]: " <<i<<"; "<<SolX[i];
    }
    
    cout<<"\n\n";
    return 0;
}

void PrintMatrix(float M[3][3])
{
    int i, j;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            cout << M[i][j] << "\n";
        }
    }
}
