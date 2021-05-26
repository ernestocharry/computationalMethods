//  Universidad Nacional Autonoma de Mexico
//  Posgrado en Ciencias Fisicas
//  Introduccion a la Fisica Computacional 
//  Profesor: Santiago Francisco Caballero Benitez
//  Autor: F. E. Charry-Pastrana 
//  27.02.2018


//  Busqueda de raices mediante Metodo de la Secante

#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <math.h>

double Function(double x); 


using namespace std;

int main()
{
    int i, j; 
    double a, b, c; 
 
    
    i = 0; 
    int nMax = 50;          // Max interaccion posibles
    double x0 = 2; 
    double x1 = 3.6; 
    double error = pow(10,-12);
    
    double x2 = x1; 
    
    ofstream myfile;
    myfile.open ("SecantMethod_Error_vs_Interations.txt");
    
    cout<<"\n Valores iniciales: "; 
    cout<<"\n i: "<<i; 
    cout<<"\n x0: "<<x0; 
    cout<<"\n x1: "<<x1; 
    cout<<"\n Fun(x0): "<<Function(x0); 

    

    myfile<<i<<"\t"<<0;
    double control =0 ;
    
    while( (i<nMax) && (control==0) )
    {
        c = Function(x1);
        x2 = x1-(Function(x1)*x1-Function(x1)*x0)/(Function(x1)-Function(x0)); 
        
        x0 = x1; 
        x1 = x2; 
        
        myfile<<"\n";

        cout<<"\n----------------------------------------------";
        cout<<"\n i: "<<i; 
        cout<<"\n x2: "<<x2;
        cout<<"\n c: "<<c;
        cout<<"\n Fun(x2): "<<Function(x2); 
        
        i = i+1; 

        myfile<<i<<"\t";
        myfile<<fixed<<setprecision(16)<<sqrt((c-Function(x2))*(c-Function(x2)));
        
        if(sqrt((c-Function(x2))*(c-Function(x2)))<error) control =1;

    }
    
    
    return 0; 
}

double Function(double x)
{
    double function; 
    function = 2*sin(x) + cos(2*x); 
    return function; 
}
