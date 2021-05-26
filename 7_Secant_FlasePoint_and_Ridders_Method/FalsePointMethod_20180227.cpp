//  Universidad Nacional Autonoma de Mexico
//  Posgrado en Ciencias Fisicas
//  Introduccion a la Fisica Computacional
//  Profesor: Santiago Francisco Caballero Benitez
//  Autor: F. E. Charry-Pastrana
//  27.02.2018


//  Busqueda de raices mediante False Point Method

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
    double fx2antes;
    
    
    i = 0;
    int nMax = 50;          // Max interaccion posibles
    double x0 = 1;
    double x1 = 5;
    double error = pow(10,-12);
    
    fx2antes = x1-(Function(x1)*x1-Function(x1)*x0)/(Function(x1)-Function(x0));
    
    double x2 = x1;
    
    ofstream myfile;
    myfile.open ("FalsePointMethod_Error_vs_Interations.txt");
    
    cout<<"\n Valores iniciales: ";
    cout<<"\n i: "<<i;
    cout<<"\n x0: "<<x0;
    cout<<"\n x1: "<<x1;
    cout<<"\n Fun(x0): "<<Function(x0);
    
    
    
    myfile<<i<<"\t"<<0;
    double control=1;
    while( (i<nMax) && (control==1) )
    {
        
        x2 = x1-(Function(x1)*x1-Function(x1)*x0)/(Function(x1)-Function(x0));
        
        cout<<"\n----------------------";
        cout<<"\n Antes";
        cout<<"\n x0: "<<x0;
        cout<<"\n x1: "<<x1;
        cout<<"\n x2: "<<x2;
        
        a = copysign(1,Function(x0));
        b = copysign(1,Function(x1));
        c = copysign(1,Function(x2));
        
        if(c==b)
        {
            x0 = x0;
            x1 = x2;
        }
        else if (c == a)
        {
            x0 = x2;
            x1 = x1;
        }
        
        
        
        cout<<"\n Despues";
        cout<<"\n x0: "<<x0;
        cout<<"\n x1: "<<x1;
        cout<<"\n x2: "<<x2;
        
        myfile<<"\n";
        
        cout<<"\n----------------------------------------------";
        cout<<"\n i: "<<i;
        cout<<"\n x2: "<<x2;
        cout<<"\n Fun(x2 antes): "<<fx2antes;
        cout<<"\n Fun(x2): "<<Function(x2);
        cout<<"\n Error: "<<fixed<<setprecision(16)<<sqrt((fx2antes-Function(x2))*(fx2antes-Function(x2)));
        
        if(sqrt((fx2antes-Function(x2))*(fx2antes-Function(x2)))<error)   control = 0;
        
        i = i+1;
        
        myfile<<i<<"\t";
        myfile<<fixed<<setprecision(16)<<sqrt((fx2antes-Function(x2))*(fx2antes-Function(x2)));
        
        fx2antes = Function(x2);
        
    }
    
    
    return 0;
}

double Function(double x)
{
    double function;
    function = 2*sin(x) + cos(2*x);
    return function; 
}
