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

void Graficar(double Theta0, double P0);

int main()
{
    // Oscilador armónico. Variables: Theta = X & P_(Theta) = Y
    int i, j;
    double PPuntos = 500;
    double Vec[2],xInicial, pInicial, Diferencia;    // vec = (x,y) = (theta, p_theta)
    double h = 0.01;
    
    Vec[1] = -1.23592;
    Vec[0] = PI/2;
    Graficar(Vec[0], Vec[1]);
    
    
    return 0;
}


void Graficar(double Theta0, double P0)
{

    ofstream myfile2;

    myfile2.open("Solucion_-1.23592.txt");
    double k1[2], k2[2], k3[2], k4[2];    //  Para X y para Y
    
    int i;
    double ti = 0;          // tiempo inicial
    double tf = 10;         // tiempo finl
    int N = 1000;             // No. de puntos
    double h = (tf-ti)/(N-1);
    double t, x0, y0, Vec[2];    // vec = (x,y) = (theta, p_theta)
    
    x0 = Theta0;
    y0 = P0;
    
    double Energia = y0*y0/2 + 1 - cos(x0);
    
    myfile2<<"0\t"<<x0<<"\t"<<y0<<"\t"<<Energia<<"\n";
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
        Vec[0] = h*(k1[0]+2*k2[0]+2*k3[0]+k4[0])/6 + x0;    // Theta
        Vec[1] = h*(k1[1]+2*k2[1]+2*k3[1]+k4[1])/6 + y0;    // P
        
        x0 = Vec[0];
        y0 = Vec[1];
        
        Energia = y0*y0/2 + 1 - cos(x0);
        
        myfile2<<t<<"\t"<<x0<<"\t"<<y0<<"\t"<<Energia<<"\n";
    }
    
    myfile2.close();

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
