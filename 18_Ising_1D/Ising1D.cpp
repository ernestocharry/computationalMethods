#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <random>


using namespace std;

const double PI  =3.141592653589793238463;


int main()
{
    ofstream myfile;
    myfile.open ("Solucion.txt");
    

    int i, j, k;
    double a, b;
    int LongitudCadena = pow(10,3); // Fijo
    int ValoresEspin[LongitudCadena];
    
    double Beta = 0.8;
    double Jota = 1;
    double DeltaE = 0;
    double R;
    double Magnet;
    double Energia;
    
    
    srand((int)time(0));
    
    //  Configuración inicial: semilla.
    double Beta0 = 0.1;
    double BetaF = 10;
    double BetaPuntos = 500;
    double BetaDelta = (BetaF-Beta0)/(BetaPuntos-1);
    
    for (int l= 0; l<BetaPuntos; l++)
    {
        Beta = BetaDelta*l+Beta0;
        
    for(i=0; i<LongitudCadena; i++)
    {
        a = (((double)rand()/(RAND_MAX))*(2)-1);
        if(a>=0)    ValoresEspin[i] = 1;
        if(a<0)     ValoresEspin[i] = -1;
    }
    
    //  Termalizar
    int InteracionesParaTermalizar = pow(10,3);
    for(i=0; i<InteracionesParaTermalizar; i++)
    {
        //  Punto aleatorio en la cadena
        j = (int)(((double)rand()/(RAND_MAX))*(LongitudCadena -1));
//        cout<<"\n b: "<<j;
        
        if(j==0)    DeltaE = 2*Jota*(ValoresEspin[LongitudCadena-1] + ValoresEspin[j+1])*ValoresEspin[j];
        if(j==LongitudCadena)    DeltaE = 2*Jota*(ValoresEspin[j-1] + ValoresEspin[0])*ValoresEspin[j];
        if((j=!0) && (j=!LongitudCadena)) DeltaE = 2*Jota*(ValoresEspin[j-1] + ValoresEspin[j+1])*ValoresEspin[j];
        
//        cout<<"\n DeltaE : "<<DeltaE;
//        cout <<"\n Valor Espin antes: "<<ValoresEspin[j];
        
        R =(((double)rand()/(RAND_MAX))*(1));

        if(R <= exp(-Beta*DeltaE))
        {
            ValoresEspin[j] = -ValoresEspin[j];
            a = 0;
            Energia = 0;
            // Calculo de magnetizacion
            for(k=0; k<LongitudCadena; k++)
            {
                a += ValoresEspin[k];
                Magnet = (sqrt(pow(a,2)))/LongitudCadena;
                
                if(k==(LongitudCadena-1))
                {
                    b = -Jota*ValoresEspin[k]*ValoresEspin[0];
                    Energia += b;
                }
                else{
                    b = -Jota*ValoresEspin[k]*ValoresEspin[k+1];
                    Energia += b;
                }
                
            }
            
        }
    }

     myfile<<Beta<<"\t"<<Energia<<"\t"<<Magnet<<"\n";
    }
    
    myfile.close();
    cout<<"\n\n";
    return 0;
}
