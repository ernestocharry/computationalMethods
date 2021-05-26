//  Universidad Nacional Autonoma de Mexico
//  Posgrado en Ciencias Fisicas
//  Introduccion a la Fisica Computacional
//  Profesor: Santiago Francisco Caballero Benitez
//  Autor: F. E. Charry-Pastrana
//  03.03.2018


//  Busqueda de raices 2D mediante METODO DE NEWTON-RAP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <math.h>

double* GaussJordan(double vector[2], double deltaX[2]);
double* Funcion(double vector[2], double Fun[2]);

using namespace std;

int main()
{
    int i;
    int nMax = 50;
    double error = pow(10,-8);
    
    double Vector[2];
    double deltaX[2];
    double Fun[2];
    double x0, y0;
    
    ofstream myfile;
    
    //Valores iniciales
    x0 = -3.5;
    y0 = 2.5;
    myfile.open ("NewtonRaphson2D_x0_-3.5_y0_2.5.txt");
    
    Vector[0] = x0;
    Vector[1] = y0;
    
    Funcion(Vector,Fun);
    
    double max = 2;
    i = 0;
    
    cout<<"\n Valores iniciales";
    cout<<"\n Valor X[0]: "<<Vector[0];
    cout<<"\n Valor X[1]: "<<Vector[1];
    cout<<"\n Valor Fun[0]: "<<Fun[0];
    cout<<"\n Valor Fun[1]: "<<Fun[1];
    cout<<"\n -----------------------------------------";
    
    while((max>error) && (i<nMax))
    {
        GaussJordan(Vector,deltaX);
        
        Vector[0] = Vector[0] +deltaX[0];
        Vector[1] = Vector[1] +deltaX[1];
        
        Funcion(Vector, Fun);
        
        if(sqrt(Fun[0]*Fun[0])>sqrt(Fun[1]*Fun[1])) max=sqrt(Fun[0]*Fun[0]);
        if(sqrt(Fun[1]*Fun[1])>sqrt(Fun[0]*Fun[0])) max=sqrt(Fun[1]*Fun[1]);
        
        cout<<"\n i: "<<i;
        cout<<"\n Valor X[0]: "<<Vector[0];
        cout<<"\n Valor X[1]: "<<Vector[1];
        cout<<"\n Valor deltaX[0]: "<<deltaX[0];
        cout<<"\n Valor deltaX[1]: "<<deltaX[1];
        cout<<"\n Valor Fun[0]: "<<Fun[0];
        cout<<"\n Valor Fun[1]: "<<Fun[1];
        cout<<"\n Valor Max: "<<max;
        cout<<"\n -----------------------------------------";
        
        myfile<<i+1<<"\t";
        myfile<<fixed<<setprecision(17)<<Vector[0];
        myfile<<fixed<<"\t"<<Vector[1];
        myfile<<"\t"<<deltaX[0];
        myfile<<"\t"<<deltaX[1];
        myfile<<"\t"<<Fun[0];
        myfile<<"\t"<<Fun[1];
        myfile<<"\t"<<max;
        myfile<<"\n";
        
        i = i+1;
        
    }

    cout<<"\n\n\n";
    myfile.close();
    return 0;
}

double* GaussJordan(double vector[2], double deltaX[2])
{
    int i,j,k;
    
    double J[2][3], L[2][3];   // It should be global variables
    double x,y;
    
    x = vector[0];
    y = vector[1];
    
    J[0][0] = y*y*sin(x*y)+0.6*pow(x-0.5,2);
    J[0][1] = 2*y-cos(x*y)+x*y*sin(x*y);
    J[0][2] = -(y*y-y*cos(x*y)+0.2*pow(x-0.5,3));
    
    J[1][0] = 2*cos(x*y-5)-2*x*y*sin(x*y-5)-2*(x+3);
    J[1][1] = -2*x*x*sin(x*y-5);
    J[1][2] = -(2*x*cos(x*y-5)-pow(x+3,2));
 /*
    J[0][0] = 3;
    J[0][1] = 1;
    J[0][2] = 22;

    J[1][0] = 4;
    J[1][1] = -3;
    J[1][2] = -1;
  */
    
  //  cout<<"\nInicio de Metodo de  Gauss-Jordan-----------------\n";
    int p;
    int NN=2;
    double a,b,c, v;
    

    
    // Proceso diagonalizacion matriz triangular superior
    for (p = 0; p < NN; p++)
    {
        for (i = p; i < NN; i++)
        {
            if (i == p)
            {
                v = J[i][i];
                for (j = p; j <=NN; j++)
                {
                    y = J[i][j];
                    J[i][j] = y / v;
                }
            }
            if (i > p)
            {
                a = J[i][p];
                for (j = p; j <= NN; j++)
                {
                    b = J[i][j];
                    c = J[p][j];
                    J[i][j] = b - a * c;
                }
            }
        }
    }
    
    //  Ubicando matriz diagonal superior en matriz diagonal
    for (i = 0; i < NN; i++)
    {
        L[i][NN] = J[NN-1-i][NN];
        for(j=0;j<NN;j++)
        {
            L[i][j] = J[NN-1-i][NN-1-j];
        }
    }
    
    // Proceso diagonalizacion de matriz triangular inferior
    for (p = 0; p < NN; p++)
    {
        for (i = p; i < NN; i++)
        {
            if (i == p)
            {
                v = L[i][i];
                for (j = p; j <=NN; j++)
                {
                    y = L[i][j];
                    L[i][j] = y / v;
                }
            }
            if (i > p)
            {
                a = L[i][p];
                for (j = p; j <= NN; j++)
                {
                    b = L[i][j];
                    c = L[p][j];
                    L[i][j] = b - a * c;
                }
            }
        }
    }

    deltaX[0] = L[1][2];    // El resultado queda invertido
    deltaX[1] = L[0][2];
  
    return deltaX;
}

double* Funcion(double vector[2], double Fun[2])
{
    double x, y;
    x = vector[0];
    y = vector[1];
    
    Fun[0] = y*y-y*cos(x*y)+0.2*pow(x-0.5,3);
    Fun[1] = 2*x*cos(x*y-5)-pow(x+3,2);
    
    return Fun;
}

