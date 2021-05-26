//  Universidad Nacional Autonoma de Mexico
//  Posgrado en Ciencias Fisicas
//  Introduccion a la Fisica Computacional 
//  Profesor: Santiago Francisco Caballero Benitez
//  Autor: F. E. Charry-Pastrana 
//  26.02.2018


//  Busqueda de raices mediante METODO DE NEWTON-RAP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <math.h>

double Function(double x); 
double Derivada(double x); 

using namespace std;



int main()
{
    int i, j; 
    double a, b, c; 
    
    i = 0; 
    int nMax = 100;          // Max interaccion posibles
    double x0 = 3; 
    double error = pow(10,-12);
    
    double x = x0;       // Valor inicial
    
    ofstream myfile;
    myfile.open ("NewtonRaphsonMethod_Error_vs_Interations.txt");
    
    cout<<"\n Valores iniciales: "; 
    cout<<"\n i: "<<i; 
    cout<<"\n x0: "<<x0; 
    cout<<"\n x: "<<x; 
    cout<<"\n Fun(x0): "<<Function(x0); 
    cout<<"\n Der(x0): "<<Derivada(x0); 
    cout<<"\n Fun(x): "<<Function(x); 
    

    myfile<<i<<"\t"<<0;
    while( (i<nMax) && (sqrt(Function(x)*Function(x))>error) )
    {
        c = Function(x);
        x = x0 - Function(x0)/Derivada(x0);
        myfile<<"\n";

        cout<<"\n----------------------------------------------";
        cout<<"\n i: "<<i; 
        cout<<"\n x: "<<x;
        cout<<"\n c: "<<c;
        cout<<"\n Fun(x): "<<Function(x); 
       
        // Escribiendo en archivo

        
        x0 = x; 
        
        i = i+1; 

        myfile<<i<<"\t";
        myfile<<fixed<<setprecision(16)<<sqrt((c-Function(x))*(c-Function(x)));
        
    }
    
    
    return 0; 
}

double Function(double x)
{
    double function; 
    function = 2*sin(x) + cos(2*x); 
    return function; 
}

double Derivada(double x)
{
    double derivada; 
    derivada = 2*cos(x) - 2*sin(2*x); 
    return derivada; 
}

