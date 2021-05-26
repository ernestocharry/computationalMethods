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

double Fun0(double t, double Theta1, double Theta2, double P1, double P2, double l);
double Fun1(double t, double Theta1, double Theta2, double P1, double P2, double l);
double Fun2(double t, double Theta1, double Theta2, double P1, double P2, double l);
double Fun3(double t, double Theta1, double Theta2, double P1, double P2, double l);


const double m = 1;
const double g = 1;

using namespace std;

const double PI  =3.141592653589793238463;

int main()
{
    ofstream myfile, CriticalTime1, CriticalTime2;
    myfile.open ("RK4_DoubleOscillator.txt");
    CriticalTime1.open("CriticalTime1.txt");
    CriticalTime2.open("CriticalTime2.txt");
    
    int i,k ;
    int j=0, jj;
    double ti = 0;// tiempo inicial
    double tf = 11;
    int N = pow(10,4);             // No. de puntos
    double h = (tf-ti)/(N-1);

    // Oscilador armónico. Variables: Theta = X & P_(Theta) = Y
    
    double t, Theta1, Theta2, P1, P2, Theta10, Theta20, P10, P20;
    double x1, x2, y1, y2;
    double Vec[4];    // vec = (x,y) = (theta1, Theta2, p_theta)
    double k1[4], k2[4], k3[4], k4[4];    //  Para X y para Y
    
    
    double OmegaIncial = -3;
    double OmegaFinal = 8;
    double OmegaPuntos = 500;
    double Omegah = (OmegaFinal-OmegaIncial)/(OmegaPuntos-1);
    double l;

    double Omega;   // Omega cuadrado
    
    
    for(k=0; k<OmegaPuntos; k++)
    {
        
        Omega = pow(10,Omegah*k + OmegaIncial);
        
        l = g/Omega;
        
        // Valores iniciales:
        Vec[0] = PI/2;     // Theta 1
        Vec[1] = PI/2;     // Theta 2
        Vec[2] = 0;       // P 1
        Vec[3] = 0;         // P 1
        
        Theta1 = Vec[0];
        Theta2 = Vec[1];
        P1 = Vec[2];
        P2 = Vec[3];
        
        Theta10 = Theta1;
        Theta20 = Theta2;
        P10 = P1;
        P20 = P2;

        j = 0;
        jj = 0;
        
        for(i=1; i<N; i++)
        {
            t = i*h + ti;
            
            k1[0] = Fun0(t,Theta1, Theta2, P1, P2, l);
            k1[1] = Fun1(t,Theta1, Theta2, P1, P2, l);
            k1[2] = Fun2(t,Theta1, Theta2, P1, P2, l);
            k1[3] = Fun3(t,Theta1, Theta2, P1, P2, l);
            
            k2[0] = Fun0(t,Theta1+k1[0]*h/2, Theta2+k1[1]*h/2, P1+k1[2]*h/2, P2+k1[3]*h/2, l);
            k2[1] = Fun1(t,Theta1+k1[0]*h/2, Theta2+k1[1]*h/2, P1+k1[2]*h/2, P2+k1[3]*h/2, l);
            k2[2] = Fun2(t,Theta1+k1[0]*h/2, Theta2+k1[1]*h/2, P1+k1[2]*h/2, P2+k1[3]*h/2, l);
            k2[3] = Fun3(t,Theta1+k1[0]*h/2, Theta2+k1[1]*h/2, P1+k1[2]*h/2, P2+k1[3]*h/2, l);
            
            k3[0] = Fun0(t,Theta1+k2[0]*h/2, Theta2+k2[1]*h/2, P1+k2[2]*h/2, P2+k2[3]*h/2, l);
            k3[1] = Fun1(t,Theta1+k2[0]*h/2, Theta2+k2[1]*h/2, P1+k2[2]*h/2, P2+k2[3]*h/2, l);
            k3[2] = Fun2(t,Theta1+k2[0]*h/2, Theta2+k2[1]*h/2, P1+k2[2]*h/2, P2+k2[3]*h/2, l);
            k3[3] = Fun3(t,Theta1+k2[0]*h/2, Theta2+k2[1]*h/2, P1+k2[2]*h/2, P2+k2[3]*h/2, l);
            
            k4[0] = Fun0(t,Theta1+k3[0]*h, Theta2+k3[1]*h, P1+k3[2]*h, P2+k3[3]*h, l);
            k4[1] = Fun1(t,Theta1+k3[0]*h, Theta2+k3[1]*h, P1+k3[2]*h, P2+k3[3]*h, l);
            k4[2] = Fun2(t,Theta1+k3[0]*h, Theta2+k3[1]*h, P1+k3[2]*h, P2+k3[3]*h, l);
            k4[3] = Fun3(t,Theta1+k3[0]*h, Theta2+k3[1]*h, P1+k3[2]*h, P2+k3[3]*h, l);
            
            
            // Runge kutta 4
            Vec[0] = h*(k1[0]+2*k2[0]+2*k3[0]+k4[0])/6 + Theta1;
            Vec[1] = h*(k1[1]+2*k2[1]+2*k3[1]+k4[1])/6 + Theta2;
            Vec[2] = h*(k1[2]+2*k2[2]+2*k3[2]+k4[2])/6 + P1;
            Vec[3] = h*(k1[3]+2*k2[3]+2*k3[3]+k4[3])/6 + P2;
            
            Theta1 = Vec[0];
            Theta2 = Vec[1];
            P1 = Vec[2];
            P2 = Vec[3];
            
            /*
             x1 = l*sin(Theta1)/2;
             x2 = l*(sin(Theta1) + 0.5*sin(Theta2));
             y1 = -l*cos(Theta1)/2;
             y2 = -l*(cos(Theta1) + 0.5*cos(Theta2));
             
             myfile<<t<<"\t"<<Theta1<<"\t"<<Theta2<<"\t"<<P1<<"\t"<<P2;
             myfile<<"\t"<<x1<<"\t"<<y1<<"\t"<<x2<<"\t"<<y2<<"\n";
             */
            
            if( sqrt(pow(Theta2,2))>PI  && j==0)
            {
                CriticalTime1<<t<<"\t"<<g<<"\t"<<l<<"\t"<<Omega<<"\t"<<Theta1<<"\t"<<Theta2<<"\t";
                CriticalTime1<<Theta10<<"\t"<<Theta20<<"\t"<<P10<<"\t"<<P20<<"\n";
                j = 2;
            }
            
            if( sqrt(pow(Theta2,2))>3*PI  && jj==0)
            {
                CriticalTime2<<t<<"\t"<<g<<"\t"<<l<<"\t"<<Omega<<"\t"<<Theta1<<"\t"<<Theta2<<"\t";
                CriticalTime2<<Theta10<<"\t"<<Theta20<<"\t"<<P10<<"\t"<<P20<<"\n";
                jj = 1;
            }

            
            if(j==2 && jj==2)
            {
                 i = N-1;
            }
            
        }
        
    }
    

    cout<<"\n\n";
    myfile.close();
    return 0;
}

double Fun0(double t, double Theta1, double Theta2, double P1, double P2, double l)
{
    double sigma = 16 - 9*pow(cos(Theta1-Theta2),2);
    double f = 6*(2*P1-3*cos(Theta1-Theta2)*P2)/(m*l*l*sigma);
    return f;
}

double Fun1(double t, double Theta1, double Theta2, double P1, double P2, double l)
{
    double sigma = 16 - 9*pow(cos(Theta1-Theta2),2);
    double f = 6*(8*P2-3*cos(Theta1-Theta2)*P1)/(m*l*l*sigma);
    return f;
}

double Fun2(double t, double Theta1, double Theta2, double P1, double P2, double l)
{
    double sigma = 16 - 9*pow(cos(Theta1-Theta2),2);
    double ThetaPunto1 = 6*(2*P1-3*cos(Theta1-Theta2)*P2)/(m*l*l*sigma);
    double ThetaPunto2 = 6*(8*P2-3*cos(Theta1-Theta2)*P1)/(m*l*l*sigma);
    double f = -m*l*l*(ThetaPunto1*ThetaPunto2*sin(Theta1-Theta2) + 3*g*sin(Theta1)/l)/2;
    return f;
}

double Fun3(double t, double Theta1, double Theta2, double P1, double P2, double l)
{
    double sigma = 16 - 9*pow(cos(Theta1-Theta2),2);
    double ThetaPunto1 = 6*(2*P1-3*cos(Theta1-Theta2)*P2)/(m*l*l*sigma);
    double ThetaPunto2 = 6*(8*P2-3*cos(Theta1-Theta2)*P1)/(m*l*l*sigma);
    double f = -m*l*l*(-ThetaPunto1*ThetaPunto2*sin(Theta1-Theta2) + g*sin(Theta2)/l)/2;
    return f;
}
