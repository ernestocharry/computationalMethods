#include <stdio.h>
#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>

double Fun0(double x, double y);
double Fun1(double x, double y);
using namespace std;
const double PI  =3.141592653589793238463;

int main()
{
  int i,j;
  double ti = 0;
  double tf = 10;
  int N = 50;
  double h = (tf-ti)/(N-1);
    
    double pow0 = 1;
    double powf = 6;
    int powPuntos = 100;
    double DeltaPow = (powf-pow0)/(powPuntos-1);
    
    
    ofstream myfile3, myfileAcumulado;
    
    
    myfile3.open ("RK4.txt");
    myfileAcumulado.open("N_Theta0_PTheta0_Tfinal_ThetaFinal_PThetaFinal_ErrorTheta_ErrorP.txt");
    
    /*
     Oscilador armonico.
     X = theta
     y = P_theta
     */
    double t, Vec[2], Vec0[2];    // vec = (x,y) = (theta, p_theta)
    double k1[2], k2[2], k3[2], k4[2];    //  Para X y para Y
            double x0, y0;
    // K1[0]  para x
    // Rk4[0] para x
    

    double AnteriorTheta = 0;
    double AnteriorP = 0;
    double ErrorTheta, ErrorP;
    
    
    
    for(j=0; j<powPuntos; j++)
    {
        N = (int)(pow(10,DeltaPow*j+pow0));
        cout<<"\n valor N: "<<N;
        
        h = (tf-ti)/(N-1);
        
        Vec[0] = PI/4;        // Posicion inicial, Angulo inicial
        Vec[1] = 0;    // Velocidad inicial
        
        
        x0 = Vec[0];
        y0 = Vec[1];    // Velocidad inicial
        
        
        
        //    myfile3<<"0\t"<<x0<<"\t"<<y0<<"\n";
        myfileAcumulado<<N<<"\t"<<x0<<"\t"<<y0;
        for(i=1; i<N; i++)
        {
            t = i*h + ti;
            
            k1[0] = Fun0(x0,y0);
            k1[1] = Fun1(x0,y0);
            
            k2[0] = Fun0(x0+k1[0]*h/2, y0+k1[1]*h/2);
            k2[1] = Fun1(x0+k1[0]*h/2, y0+k1[1]*h/2);
            
            k3[0] = Fun0(x0+k2[0]*h/2, y0+k2[1]*h/2);
            k3[1] = Fun1(x0+k2[0]*h/2, y0+k2[1]*h/2);
            
            k4[0] = Fun0(x0+k3[0]*h, y0+k3[1]*h);
            k4[1] = Fun1(x0+k3[0]*h, y0+k3[1]*h);
            
            // Runge kutta 4
            Vec[0] = h*(k1[0]+2*k2[0]+2*k3[0]+k4[0])/6 + x0;
            Vec[1] = h*(k1[1]+2*k2[1]+2*k3[1]+k4[1])/6 + y0;
            
            x0 = Vec[0];
            y0 = Vec[1];
            
            //  myfile3<<t<<"\t"<<x0<<"\t"<<y0<<"\n";
        }
        ErrorTheta = sqrt(pow(AnteriorTheta-x0,2));
        ErrorP = sqrt(pow(AnteriorP-y0,2));
        AnteriorTheta = x0;
        AnteriorP = y0;
        myfileAcumulado<<fixed<<setprecision(16);
        myfileAcumulado<<"\t"<<t<<"\t"<<x0<<"\t"<<y0;
        myfileAcumulado<<"\t"<<ErrorTheta<<"\t"<<ErrorP<<"\n";
    }
    





  myfileAcumulado .close();
  
  return 0; 
}

double Fun0(double x, double y)
{
  double f = y;
  return f; 
}

double Fun1(double x, double y)
{
    double f = -sin(x);
    return f;
}
