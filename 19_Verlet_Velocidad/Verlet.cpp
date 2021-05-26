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

using namespace std;

const double PI  =3.141592653589793238463;


int main()
{
    ofstream myfile, myfile2;
    myfile.open ("Solucion.txt");
    
    // Oscilador armónico. Variables: Theta = X & P_(Theta) = Y
    int i, j, k;
    
    double tInicial = 0;
    double tFinal = 2;
    int	 tPuntos = 10000;
    double tDelta = (tFinal-tInicial)/(tPuntos-1);

    double VecR[tPuntos][2],  VecV[tPuntos][2];

        double kConstante = 39.5;
    
    //  Condiciones iniciales
    VecR[0][0] = 1.97;      //  X0
    VecR[0][1] = 0;         //  Y0
    VecV[0][0] = 0;         // Vx0
    VecV[0][1] = 0.816;     // Vy0
    
    double x, y, vx, vy, r, h, t;
    r = sqrt(VecR[j][0]*VecR[j][0]+VecR[j][1]*VecR[j][1]);
    
    myfile<<t<<"\t"<<VecR[j][0]<<"\t"<<VecR[j][1]<<"\t"<<r<<"\t"<<VecV[j][0]<<"\t"<<VecV[j][1]<<"\t"<<sqrt(VecV[j][0]*VecV[j][0]+VecV[j][1]*VecV[j][1])<<"\n";
    for(j=1; j<tPuntos; j++)
    {
        h = tDelta;
        t = j*tDelta+tInicial;
        
        x = VecR[j-1][0];
        y = VecR[j-1][1];
        vx = VecV[j-1][0];
        vy = VecV[j-1][1];
        
        VecR[j][0] = x + tDelta*vx - h*h*kConstante*x/(2*pow(x*x+y*y,1.5));
        VecR[j][1] = y + tDelta*vy - h*h*kConstante*y/(2*pow(x*x+y*y,1.5));
    
        VecV[j][0] = vx - h*(kConstante*x/pow(x*x+y*y,1.5) +kConstante*VecR[j][0]/(pow(VecR[j][0]*VecR[j][0]+VecR[j][1]*VecR[j][1],1.5)))/2;
        VecV[j][1] = vy - h*(kConstante*y/pow(x*x+y*y,1.5) +kConstante*VecR[j][1]/(pow(VecR[j][0]*VecR[j][0]+VecR[j][1]*VecR[j][1],1.5)))/2;

        r = sqrt(VecR[j][0]*VecR[j][0]+VecR[j][1]*VecR[j][1]);
        
        myfile<<t<<"\t"<<VecR[j][0]<<"\t"<<VecR[j][1]<<"\t"<<r<<"\t"<<VecV[j][0]<<"\t"<<VecV[j][1]<<"\t"<<sqrt(VecV[j][0]*VecV[j][0]+VecV[j][1]*VecV[j][1])<<"\n";
    }
    
    
    myfile.close();
    return 0;
}
