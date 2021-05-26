//  Universidad Nacional Autonoma de Mexico
//  Posgrado en Ciencias Fisicas
//  Introduccion a la Fisica Computacional 
//  Profesor: Santiago Francisco Caballero Benitez
//  Autor: F. E. Charry-Pastrana 
//  27.02.2018


//  Busqueda de raices mediante Ridders' Method

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
    double a, b, c, signo; 
    double x1, x2, x3, x4; 
    double FunAntes; 
    ofstream myfile;
    
    myfile.open ("RiddersMethod_Error_vs_Interations.txt"); 
    
    i = 0; 
    int nMax = 50;          // Max interaccion posibles
    x1 = 1; 
    x2 = 5; 

    x4 = x1; 
    
    double error = pow(10,-12);
    
    FunAntes = Function(x4); 
    

    cout<<"\n Valores iniciales: "; 
    cout<<"\n i: "<<i; 
    cout<<"\n x1: "<<x1; 
    cout<<"\n x2: "<<x2; 
    cout<<"\n x4: "<<x4; 
    cout<<"\n Fun(x4): "<<Function(x4); 

    
    double raiz; 
    myfile<<i<<"\t"<<0;
    int control = 0;
    while( (i<nMax) && (control==0) )
    {
        x3 = (x1+x2)/2; 
        
        signo = copysign(1, Function(x1) - Function(x2)); 
        raiz = sqrt( pow(Function(x3),2) - Function(x1)*Function(x2)); 
        
        x4 = x3 - (x3-x2)*signo*Function(x3)/raiz; 
        
        cout<<"\n----------------------"; 
        cout<<"\n Antes"; 
        cout<<"\n x1: "<<x1; 
        cout<<"\n x2: "<<x2; 
        cout<<"\n x3: "<<x3; 
        cout<<"\n x4: "<<x4; 
        
        
        a = copysign(1,Function(x1)); 
        b = copysign(1,Function(x2));
        c = copysign(1,Function(x4)); 
        
        if( a*c < 0)
        {
            x1 = x1; 
            x2 = x4; 
        }
        else if (b*c<0 )
        {
            x1 = x4; 
            x2 = x2; 
        }

        cout<<"\n Despues"; 
        cout<<"\n x1: "<<x1; 
        cout<<"\n x2: "<<x2; 
        cout<<"\n x3: "<<x3; 
        cout<<"\n x4: "<<x4; 
        
        myfile<<"\n";

        cout<<"\n----------------------------------------------";
        cout<<"\n i: "<<i; 
        cout<<"\n x2: "<<x2;
        cout<<"\n Fun(x4 antes): "<<FunAntes;
        cout<<"\n Fun(x4): "<<Function(x4); 
        cout<<"\n Error: "<<fixed<<setprecision(16)<<sqrt((FunAntes-Function(x4))*(FunAntes-Function(x4)));
        
        i = i+1; 

        myfile<<i<<"\t";
        myfile<<fixed<<setprecision(16)<<sqrt((FunAntes-Function(x4))*(FunAntes-Function(x4)));
        
        if(sqrt((FunAntes-Function(x4))*(FunAntes-Function(x4)))<error) control = 1;
        
        FunAntes = Function(x4); 
    }
    
    
    return 0; 
}

double Function(double x)
{
    double function; 
    function = 2*sin(x) + cos(2*x); 
    return function; 
}



