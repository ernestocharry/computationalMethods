#include <iostream>
#include <time.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>  // Setpresition
#include <math.h>

using namespace std;

double Funcion1(double x);
void GraficandoFuncion(double x0, double x1);

int main()
{
    ofstream myfileTarea12Integrales;
    
    double SumaPares;
    double SumaImpares;
    double SumaParesTres;
    double SumaImparesTres;
    
    double IntegralTrapezio;
    double IntegralSimpsonTresCuartos;
    double IntegralSimpsonTresOctavos;
    
    double AntIntegralTrapezio = 1;
    double AntIntegralSimpsonTresCuartos = 1;
    double AntIntegralSimpsonTresOctavos = 1;
    
    double ErrRelIntegralTrapezio = 0;
    double ErrRelIntegralSimpsonTresCuartos = 0;
    double ErrRelIntegralSimpsonTresOctavos = 0;
    
    double x;
    
    int i,j;
    double x0, xf, deltaX;
    int Nmin = 3;
    int Nmax = 20;
    int xN;
    
    myfileTarea12Integrales.open("N_Integral_ErrRelativo.txt");
    
    double x1, xsim, xsim1, xsim2;
    
    double a, b, c;
    x0 = 0;
    xf = 10;

    GraficandoFuncion(x0,xf); 
    
    for(j = Nmin; j<= Nmax; j++ )
    {
        xN  = pow(2,j);
        deltaX = (xf - x0)/(xN-1);
        
        IntegralTrapezio = 0;
        IntegralSimpsonTresCuartos = 0;
        IntegralSimpsonTresOctavos = 0;

        for(i=1;i<(xN-1);i++)
        {
            a = IntegralTrapezio;
            b = IntegralSimpsonTresCuartos;
            c = IntegralSimpsonTresOctavos;
            
            //  Limites extremos
            x = deltaX*i + x0;
            x1 = deltaX*(i+1) + x0;
            
            //  Para simpson 3-4
            xsim = (x+x1)/2;
            
            //  Para simpson 3-8
            xsim1 = (2*x + x1)/3;
            xsim2 = (x + 2*x1)/3;
            
            //  Hay que multiplicar por dos porque la funcion es par y el intervalo es par
            
            IntegralTrapezio = a + 2*(Funcion1(x) + Funcion1(x1))*(x1-x)/2;
            
            IntegralSimpsonTresCuartos = b + 2*(Funcion1(x) + 4*Funcion1(xsim) + Funcion1(x1))*(x1-x)/6;
            
            IntegralSimpsonTresOctavos = c + 2*(Funcion1(x) + 3*Funcion1(xsim1) + 3*Funcion1(xsim2) + Funcion1(x1))*(x1-x)/8;
        }
        
        ErrRelIntegralTrapezio = sqrt(pow(1-IntegralTrapezio/AntIntegralTrapezio,2));
        AntIntegralTrapezio = IntegralTrapezio;
        
        ErrRelIntegralSimpsonTresCuartos = sqrt(pow(1-IntegralSimpsonTresCuartos/AntIntegralSimpsonTresCuartos,2));
        AntIntegralSimpsonTresCuartos = IntegralSimpsonTresCuartos;
        
        ErrRelIntegralSimpsonTresOctavos = sqrt(pow(1-IntegralSimpsonTresOctavos/AntIntegralSimpsonTresOctavos,2));
        AntIntegralSimpsonTresOctavos = IntegralSimpsonTresOctavos;

        
        cout<<"\n---------------------------------------------";
        cout<<"\n "<<j;
        cout<<"\n Valor integral Trapezio: ";
        cout<<fixed<<setprecision(9)<<IntegralTrapezio;
        cout<<"\n Error Relativo Trapezio: "<<ErrRelIntegralTrapezio;
        cout<<"\n";
        cout<<"\n Valor integral Simp 3-4: "<<IntegralSimpsonTresCuartos;
        cout<<"\n Error Relativo Simp 3-4: "<<ErrRelIntegralSimpsonTresCuartos;
        cout<<"\n";
        cout<<"\n Valor integral Simp 3-8: "<<IntegralSimpsonTresOctavos;
        cout<<"\n Error Relativo Simp 3-8: "<<ErrRelIntegralSimpsonTresOctavos;
        cout<<"\n---------------------------------------------";
        

        myfileTarea12Integrales<<j;
        myfileTarea12Integrales<<"\t";
        myfileTarea12Integrales<<fixed<<setprecision(16)<<IntegralTrapezio;
        myfileTarea12Integrales<<"\t"<<ErrRelIntegralTrapezio;

        myfileTarea12Integrales<<"\t"<<IntegralSimpsonTresCuartos;
        myfileTarea12Integrales<<"\t"<<ErrRelIntegralSimpsonTresCuartos;

        myfileTarea12Integrales<<"\t"<<IntegralSimpsonTresOctavos;
        myfileTarea12Integrales<<"\t"<<ErrRelIntegralSimpsonTresOctavos;
        myfileTarea12Integrales<<"\n";
    }
    
  
    
    cout<<"\n\n";
    return 0;
}

double Funcion1(double x)
{
    double F1 = sin(M_PI*x)/(M_PI*x);
    return F1;
}

void GraficandoFuncion(double x0, double x1)
{
    int i;
    double x;
    ofstream fileFuncion;
    fileFuncion.open("Funcion_SinX_X.txt");
    
    int nX = 1000;
    double deltaX = (x1-x0)/(nX-1);
    
    
    for(i=1; i<nX; i++)
    {
        x = deltaX*i + x0;
        fileFuncion<<x<<"\t"<< sin(M_PI*x)/(M_PI*x)<<"\n";
        
    }
    fileFuncion.close();
    
}
