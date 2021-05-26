#include <stdio.h>
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std; 
double function(double x, double y);

int main()
{
  int i; 
  double xi = 0;
  double xf = 30;
  int N = 1000;
  double h = (xf-xi)/(N-1);

  double x, y;
  double x0, y0;

  double k1, k2, k3, k4; 
  double y_Euler, y_MidPoint, y_RK4; 

  ofstream myfile1, myfile2, myfile3;

  myfile1.open ("Euler.txt");
  myfile2.open ("MidPoint.txt");
  myfile3.open ("RK4.txt");

  x0 = 0;
  y0 = 1;
  for(i=1; i<N; i++)
    {
      x = i*h + xi; 
      k1 = function(x0, y0);
      y_Euler= h*k1 + y0;

      x0 = x;
      y0 = y_Euler; 
     
      myfile1<<x<<"\t"<<y_Euler<<"\n"; 
    }
  
  x0 = 0;
  y0 = 1; 
  for(i=1; i<N; i++)
    {
      x = i*h + xi; 
    
      k2 = function(x0+h/2, y0+k1*h/2);
      
      y_MidPoint = h*k2 + y0; 

      x0 = x;
      y0 = y_MidPoint; 
     
      myfile2<<x<<"\t"<<y_MidPoint<<"\n"; 
    }
  
  x0 = 0;
  y0 = 1; 
  for(i=1; i<N; i++)
    {
      x = i*h + xi; 
    
      k1 = function(x0, y0);
      k2 = function(x0+h/2, y0+k1*h/2);
      k3 = function(x0+h/2, y0+k2*h/2);
      k4 = function(x0+h/2, y0+k3*h);
      
      y_RK4 = h*(k1+2*k2+2*k3+k4)/6 + y0; 

      x0 = x;
      y0 = y_RK4; 
     
      myfile3<<x<<"\t"<<y_RK4<<"\n"; 
    }

  
  myfile1.close();
  myfile2.close();
  myfile3.close();
  
  return 0; 
}

double function(double x, double y)
{
  double f = y*cos(x+y); 
  return f; 
}
