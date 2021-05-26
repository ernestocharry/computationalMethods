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

double Funcional(double Theta0, double P0);
void Graficar(double Theta0, double P0);

int main()
{
    ofstream myfile, myfile2;
    
    // Oscilador armónico. Variables: Theta = X & P_(Theta) = Y
    int i, j;
    double PPuntos = 100;
    double Vec[2],xInicial, pInicial, Diferencia;    // vec = (x,y) = (theta, p_theta)
    double h = 0.01;
    
    Vec[1] = 1; // Momento INICIAL
    for(j=0; j<PPuntos; j++)
    {
        Vec[0] = PI/2;
        xInicial = Vec[0];
        pInicial = Vec[1];
        
        Vec[1] = pInicial - (h*Funcional(Vec[0], pInicial))/( Funcional(Vec[0], pInicial+h) - Funcional(Vec[0], pInicial) );

    }
    
    Graficar(Vec[0], Vec[1]);
    
    
    myfile.close();
    return 0;
}

double Funcional(double Theta0, double P0)
{
    double Diferencia;
    double k1[2], k2[2], k3[2], k4[2];    //  Para X y para Y
    
    int i;
    double ti = 0;          // tiempo inicial
    double tf = 10;         // tiempo finl
    int N = 1000;             // No. de puntos
    double h = (tf-ti)/(N-1);
    double t, x0, y0, Vec[2];    // vec = (x,y) = (theta, p_theta)

    x0 = Theta0;
    y0 = P0;
    
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
    }
    
    Diferencia = x0 - Theta0;
    return Diferencia;
}

void Graficar(double Theta0, double P0)
{

    ofstream myfile2;

    myfile2.open("Solucion.txt");
    double k1[2], k2[2], k3[2], k4[2];    //  Para X y para Y
    
    int i;
    double ti = 0;          // tiempo inicial
    double tf = 10;         // tiempo finl
    int N = 1000;             // No. de puntos
    double h = (tf-ti)/(N-1);
    double t, x0, y0, Vec[2];    // vec = (x,y) = (theta, p_theta)
    
    x0 = Theta0;
    y0 = P0;
    
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
        
        myfile2<<t<<"\t"<<x0<<"\t"<<y0<<"\n";
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
