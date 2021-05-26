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

double Fun0(double t, double Theta1, double Theta2, double P1, double P2);
double Fun1(double t, double Theta1, double Theta2, double P1, double P2);
double Fun2(double t, double Theta1, double Theta2, double P1, double P2);
double Fun3(double t, double Theta1, double Theta2, double P1, double P2);

const double l = 1;
const double m = 1;
const double g = 1;

using namespace std;

const double PI  =3.141592653589793238463;

int main()
{
    ofstream myfile;
    myfile.open ("RK4_DoubleOscillator.txt");

    int i;
    double ti = 0;          // tiempo inicial
    double tf = 26.52;         // tiempo finl
    int N = pow(10,4);             // No. de puntos
    double h = (tf-ti)/(N-1);

    // Oscilador armónico. Variables: Theta = X & P_(Theta) = Y
    
    double t, Theta1, Theta2, P1, P2, Theta10, Theta20, P10, P20;
    double x1, x2, y1, y2;
    double Vec[4];    // vec = (x,y) = (theta1, Theta2, p_theta)
    double k1[4], k2[4], k3[4], k4[4];    //  Para X y para Y
    


    // Valores iniciales:
    Vec[0] = PI/2;     // Theta 1
    Vec[1] = PI/4;     // Theta 2
    Vec[2] = 0;       // P 1
    Vec[3] = 0;         // P 1
    
    Theta1 = Vec[0];
    Theta2 = Vec[1];
    P1 = Vec[2];
    P2 = Vec[3];
    

    x1 = l*sin(Theta1)/2;
    x2 = l*(sin(Theta1) + 0.5*sin(Theta2));
    y1 = -l*cos(Theta1)/2;
    y2 = -l*(cos(Theta1) + 0.5*cos(Theta2));
    
    myfile<<"#Tiempo\t Theta1 \t Theta2 \t P1 \t P2 \t x1 \t y1 \t x2 \t y2\n";
    myfile<<"0\t"<<Theta1<<"\t"<<Theta2<<"\t"<<P1<<"\t"<<P2;
    myfile<<"\t"<<x1<<"\t"<<y1<<"\t"<<x2<<"\t"<<y2<<"\n";
    
    for(i=1; i<N; i++)
    {
        t = i*h + ti;

        k1[0] = Fun0(t,Theta1, Theta2, P1, P2);
        k1[1] = Fun1(t,Theta1, Theta2, P1, P2);
        k1[2] = Fun2(t,Theta1, Theta2, P1, P2);
        k1[3] = Fun3(t,Theta1, Theta2, P1, P2);
        
        k2[0] = Fun0(t,Theta1+k1[0]*h/2, Theta2+k1[1]*h/2, P1+k1[2]*h/2, P2+k1[3]*h/2);
        k2[1] = Fun1(t,Theta1+k1[0]*h/2, Theta2+k1[1]*h/2, P1+k1[2]*h/2, P2+k1[3]*h/2);
        k2[2] = Fun2(t,Theta1+k1[0]*h/2, Theta2+k1[1]*h/2, P1+k1[2]*h/2, P2+k1[3]*h/2);
        k2[3] = Fun3(t,Theta1+k1[0]*h/2, Theta2+k1[1]*h/2, P1+k1[2]*h/2, P2+k1[3]*h/2);
        
        k3[0] = Fun0(t,Theta1+k2[0]*h/2, Theta2+k2[1]*h/2, P1+k2[2]*h/2, P2+k2[3]*h/2);
        k3[1] = Fun1(t,Theta1+k2[0]*h/2, Theta2+k2[1]*h/2, P1+k2[2]*h/2, P2+k2[3]*h/2);
        k3[2] = Fun2(t,Theta1+k2[0]*h/2, Theta2+k2[1]*h/2, P1+k2[2]*h/2, P2+k2[3]*h/2);
        k3[3] = Fun3(t,Theta1+k2[0]*h/2, Theta2+k2[1]*h/2, P1+k2[2]*h/2, P2+k2[3]*h/2);
        
        k4[0] = Fun0(t,Theta1+k3[0]*h, Theta2+k3[1]*h, P1+k3[2]*h, P2+k3[3]*h);
        k4[1] = Fun1(t,Theta1+k3[0]*h, Theta2+k3[1]*h, P1+k3[2]*h, P2+k3[3]*h);
        k4[2] = Fun2(t,Theta1+k3[0]*h, Theta2+k3[1]*h, P1+k3[2]*h, P2+k3[3]*h);
        k4[3] = Fun3(t,Theta1+k3[0]*h, Theta2+k3[1]*h, P1+k3[2]*h, P2+k3[3]*h);
        
        
        // Runge kutta 4
        Vec[0] = h*(k1[0]+2*k2[0]+2*k3[0]+k4[0])/6 + Theta1;
        Vec[1] = h*(k1[1]+2*k2[1]+2*k3[1]+k4[1])/6 + Theta2;
        Vec[2] = h*(k1[2]+2*k2[2]+2*k3[2]+k4[2])/6 + P1;
        Vec[3] = h*(k1[3]+2*k2[3]+2*k3[3]+k4[3])/6 + P2;
        
        Theta1 = Vec[0];
        Theta2 = Vec[1];
        P1 = Vec[2];
        P2 = Vec[3];
        
        x1 = l*sin(Theta1)/2;
        x2 = l*(sin(Theta1) + 0.5*sin(Theta2));
        y1 = -l*cos(Theta1)/2;
        y2 = -l*(cos(Theta1) + 0.5*cos(Theta2));
        
        if(sqrt(pow(Theta2,2))>PI)  cout<<"\n TC :"<<t<<"\n\n";
        
        myfile<<t<<"\t"<<Theta1<<"\t"<<Theta2<<"\t"<<P1<<"\t"<<P2;
        myfile<<"\t"<<x1<<"\t"<<y1<<"\t"<<x2<<"\t"<<y2<<"\n";
    }
    myfile.close();
    return 0;
}

double Fun0(double t, double Theta1, double Theta2, double P1, double P2)
{
    double sigma = 16 - 9*pow(cos(Theta1-Theta2),2);
    double f = 6*(2*P1-3*cos(Theta1-Theta2)*P2)/(m*l*l*sigma);
    return f;
}

double Fun1(double t, double Theta1, double Theta2, double P1, double P2)
{
    double sigma = 16 - 9*pow(cos(Theta1-Theta2),2);
    double f = 6*(8*P2-3*cos(Theta1-Theta2)*P1)/(m*l*l*sigma);
    return f;
}

double Fun2(double t, double Theta1, double Theta2, double P1, double P2)
{
    double sigma = 16 - 9*pow(cos(Theta1-Theta2),2);
    double ThetaPunto1 = 6*(2*P1-3*cos(Theta1-Theta2)*P2)/(m*l*l*sigma);
    double ThetaPunto2 = 6*(8*P2-3*cos(Theta1-Theta2)*P1)/(m*l*l*sigma);
    double f = -m*l*l*(ThetaPunto1*ThetaPunto2*sin(Theta1-Theta2) + 3*g*sin(Theta1)/l)/2;
    return f;
}

double Fun3(double t, double Theta1, double Theta2, double P1, double P2)
{
    double sigma = 16 - 9*pow(cos(Theta1-Theta2),2);
    double ThetaPunto1 = 6*(2*P1-3*cos(Theta1-Theta2)*P2)/(m*l*l*sigma);
    double ThetaPunto2 = 6*(8*P2-3*cos(Theta1-Theta2)*P1)/(m*l*l*sigma);
    double f = -m*l*l*(-ThetaPunto1*ThetaPunto2*sin(Theta1-Theta2) + g*sin(Theta2)/l)/2;
    return f;
}
