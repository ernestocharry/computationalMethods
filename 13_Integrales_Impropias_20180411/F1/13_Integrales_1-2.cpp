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
    myfileTarea12Integrales.open("F1_Integral_Error.txt");
    
    double x,t;     // Variables
    double a, b, c, d;  // Limites de integracion
    
    int N;  // Grid en espacio t
    double deltaN;
    
    a = 0;
    b = 1;

    c = 0; // Cambio de variable es simetrico
    d = +3.5;
    double Integral;
    double delta, dxdt,q;
    
    
    int NMin = 5;
    int NMax = 20;
    double IntegralAnterior=0;
    double Error;
    
    for(j =NMin; j<NMax+1; j++)
    {
        N = j;
        deltaN = (d-c)/(N-1);
        Integral = Function_F((a+b)/2)*(b-a)*deltaN/2;
        for(i=1; i<N; i++)
        {
            t = deltaN*i + c;
            x = (b+a)/2 + (b-a)*tanh(sinh(t))/2;
            q = exp(-2*sinh(t));
            dxdt = 2*(b-a)*q*cosh(t)/pow(1+q,2);
            delta = b-x;
            Integral += (Function_F(a+delta) + Function_F(b-delta))*dxdt*deltaN;
        }
        cout<<"\n \n Valor integral: "<<Integral;
        Error = pow((Integral-IntegralAnterior)*(Integral-IntegralAnterior),0.5);
        IntegralAnterior = Integral;
        myfileTarea12Integrales<<N<<fixed<<setprecision(16);
        myfileTarea12Integrales<<"\t"<<Integral<<"\t"<<Error<<"\n";
        
    }
    

    GraficandoFuncion(0,0.9999);
    myfileTarea12Integrales.close();
    cout<<"\n\n";
    return 0;
}

double Function_F(double x)
{
    double f = log(x)*log(1-x);
    return f;
}


void GraficandoFuncion(double x0, double x1)
{
    int i;
    double x;
    ofstream fileFuncion;
    fileFuncion.open("F1.txt");
    
    int nX = 1000;
    double deltaX = (x1-x0)/(nX-1);
    
    
    for(i=1; i<nX; i++)
    {
        x = deltaX*i + x0;
        fileFuncion<<x<<"\t"<< Function_F(x)<<"\n";
        
    }
    fileFuncion.close();
    
}
