//  Universidad Nacional Autonoma de Mexico
//  Posgrado en Ciencias Fisicas
//  Introduccion a la Fisica Computacional 
//  Profesor: Santiago Francisco Caballero Benitez
//  Autor: F. E. Charry-Pastrana 
//  26.02.2018


//  Busqueda de raices mediante METODO DE BISECCION

#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <math.h>

double Function(double x); 

using namespace std;



int main()
{
    int i, j; 
    double a, b, c; 
    
    i = 0; 
    int nMax = 100;          // Max interaccion posibles
    double x0 = 3; 
    double x1 = 3.6; 
    double error = pow(10,-12);
    
    double x = +(x0+x1)/2;       // Valor inicial 
    
    ofstream myfile;
    myfile.open ("BisectionMethod_Error_vs_Interations.txt");
    
    cout<<"\n Valores iniciales: "; 
    cout<<"\n i: "<<i; 
    cout<<"\n x0: "<<x0; 
    cout<<"\n x: "<<x; 
    cout<<"\n x1: "<<x1; 
    cout<<"\n Fun(x0): "<<Function(x0); 
    cout<<"\n Fun(x): "<<Function(x); 
    cout<<"\n Fun(x1): "<<Function(x1); 
    
    //                          Poner control
    double s = copysign(1, x);  //  Signo
    double anterior = 0;
    cout<<"\n Signo: "<<s;
    
    // Escribiendo en archivo
    myfile<<i<<"\t"<<"0";
    
    while( (i<nMax) && (sqrt(Function(x)*Function(x))>error) )
    {
        myfile<<"\n";
        
        s = copysign(1,Function(x));
        cout<<"\n----------------------------------------------"; 
        cout<<"\n i: "<<i; 
        cout<<"\n x: "<<x; 
        cout<<"\n Fun(x): "<<Function(x); 
        cout<<"\n Signo de Fun(x): "<<s; 
       
        a = Function(x0); 
        b = Function(x1); 
        c = Function(x);
        
        anterior = c;
        
        if( copysign(1,c)==copysign(1,a) )
        {
            x0 = x; 
        }
        if( copysign(1,c)==copysign(1,b) )
        {
            x1 = x; 
        }
        
        x = (x0+x1)/2;
        i = i+1;
        
        // Escribiendo en archivo
        myfile<<i<<"\t";
        myfile<<fixed<<setprecision(16)<<sqrt((c-Function(x))*(c-Function(x)));

        

        
        cout<<"\n Fun(x) despues: "<<Function(x);
        

        
    }
    
    myfile.close();
    
    
    return 0; 
}

double Function(double x)
{
    double function; 
    function = 2*sin(x) + cos(2*x); 
    return function; 
}
