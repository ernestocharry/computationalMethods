/*
Universidad Nacional Autónoma de México 
 Presentado por: Felix Ernesto Charry Pastrana
 Presentado a: Santiago Caballero 
 Introduccion a Física Computacional 
 2018.04.19
*/
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>

double Fun0(double t, double x, double y);
double Fun1(double t, double x, double y);

using namespace std;

const double PI  =3.141592653589793238463;

int main()
{
    ofstream myfile;
    myfile.open ("RK4.txt");
    
    int i;
    double ti = 0;          // tiempo inicial
    double tf = 15;         // tiempo finl
    int N = 1000;             // No. de puntos
    double h = (tf-ti)/(N-1);

    // Oscilador armónico. Variables: Theta = X & P_(Theta) = Y
    

    double t, x0, y0,  Vec[2], Vec0[2];    // vec = (x,y) = (theta, p_theta)
    double xAprox, xInicial, pInicial;
    double k1[2], k2[2], k3[2], k4[2];    //  Para X y para Y
    


    // Valores iniciales:
    Vec[0] = PI/16;     // Posicion inicial, Angulo inicial
    Vec[1] = 1*0;         // Momento inicial
    
    x0 = Vec[0];
    y0 = Vec[1];
    
    xInicial = x0;
    pInicial = y0;
    xAprox = x0;

    
    myfile<<"0\t"<<x0<<"\t"<<xAprox<<"\t"<<y0<<"\n";
    for(i=1; i<N; i++)
    {
        t = i*h + ti;

        k1[0] = Fun0(t,x0,y0);
        k1[1] = Fun1(t,x0,y0);
        
        k2[0] = Fun0(t,x0+k1[0]*h/2, y0+k1[1]*h/2);
        k2[1] = Fun1(t,x0+k1[0]*h/2, y0+k1[1]*h/2);
        
        k3[0] = Fun0(t,x0+k2[0]*h/2, y0+k2[1]*h/2);
        k3[1] = Fun1(t,x0+k2[0]*h/2, y0+k2[1]*h/2);
        
        k4[0] = Fun0(t,x0+k3[0]*h, y0+k3[1]*h);
        k4[1] = Fun1(t,x0+k3[0]*h, y0+k3[1]*h);
        
        // Runge kutta 4
        Vec[0] = h*(k1[0]+2*k2[0]+2*k3[0]+k4[0])/6 + x0;
        Vec[1] = h*(k1[1]+2*k2[1]+2*k3[1]+k4[1])/6 + y0;
        
        x0 = Vec[0];
        xAprox = pInicial*sin(t) + xInicial*cos(t); // Valor Angulo con Aprox
        y0 = Vec[1];
     
        myfile<<t<<"\t"<<x0<<"\t"<<xAprox<<"\t"<<y0<<"\n";
    }
    myfile.close();
    return 0;
}

double Fun0(double t, double x, double y)
{
  double f = y;
  return f; 
}

double Fun1(double t, double x, double y)
{
    double f = -sin(x);
    return f;
}
