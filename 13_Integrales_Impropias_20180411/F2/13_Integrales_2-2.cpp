#include <iostream>
#include <time.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>  // Setpresition
#include <math.h>

using namespace std;


void GraficandoFuncion(double x0, double x1);

double Function_F(double x);

int main()
{
    int i,j;
    ofstream myfileTarea12Integrales;
    myfileTarea12Integrales.open("F2_Integral_Error.txt");
    
    double x,t;     // Variables
    double a, b, c, d;  // Limites de integracion
    
    int N;  // Grid en espacio t
    double deltaN;
    

    c = -4.5; // Cambio de variable es simetrico
    d = +4;
    double Integral;
    double delta, dxdt;
    
    
    int NMin = 5;
    int NMax = 35;
    double IntegralAnterior=0;
    double Error;
    
    for(j =NMin; j<NMax+1; j++)
    {
        N = j;
        deltaN = (d-c)/(N-1);
        Integral = 0;
        for(i=0; i<N; i++)
        {
            t = deltaN*i + c;
            x = exp(M_PI*sinh(t));
            dxdt = M_PI*cosh(t)*x;
            Integral += deltaN*Function_F(x)*dxdt;
           // cout<<"\n"<<t<<"\t"<<x;
        }
        cout<<"\n \n Valor integral: "<<Integral;
        Error = pow((Integral-IntegralAnterior)*(Integral-IntegralAnterior),0.5);
        IntegralAnterior = Integral;
        myfileTarea12Integrales<<N<<fixed<<setprecision(16);
        myfileTarea12Integrales<<"\t"<<Integral<<"\t"<<Error<<"\n";
        
    }
    

    GraficandoFuncion(0,10);
    myfileTarea12Integrales.close();
    cout<<"\n\n";
    return 0;
}

double Function_F(double x)
{
    double f = pow(pow(x,0.5)*(1+x),-1);
    return f;
}


void GraficandoFuncion(double x0, double x1)
{
    int i;
    double x;
    ofstream fileFuncion;
    fileFuncion.open("F2.txt");
    
    int nX = 1000;
    double deltaX = (x1-x0)/(nX-1);
    
    
    for(i=1; i<nX; i++)
    {
        x = deltaX*i + x0;
        fileFuncion<<x<<"\t"<< Function_F(x)<<"\n";
        
    }
    fileFuncion.close();
    
}
