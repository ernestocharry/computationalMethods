#include <iostream>
#include <time.h>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
	cout << "\n\n---------------------------------------------------------------";
	cout << "\nInicio programa";
	cout << "\nFinalidad: interpolacion";

	int i, j, M;
    ofstream myfile, myfile1, myfile2, myfile3;
    myfile.open("x_y_aleatorio_initial_data.txt");
    myfile1.open("x_y_fit.txt");
    myfile2.open("x_logY_logY-Error_logY+Error.txt");
    myfile3.open("x_y_y-error_y+error.txt");
    
	M = 150;                 //  Numeros de No. aleatorio
	double xMin = 0;        //  Limites del intervalo
	double xMax = 2;

	double xAleatorio[M];   //  Vector Aleatorio
    double yAleatorioLog[M];
	double yAleatorio[M];   //  Calculo de la funcion en los puntos de xAleatorio
	double x, y, logy;            //  Variales auxiliares
    
    //  Generando numeros aleatorios
	for (i = 0; i<M; i++)
	{
        srand(time(NULL) + rand());
        
        x = (double)rand() / double(RAND_MAX);
        y = (double)rand() / double(RAND_MAX);
        
		xAleatorio[i] = (xMax-xMin)*x  + xMin;
        y = (0.1 - (-0.1))*y - 0.1;
       /*
        cout<<"\n--------------------------------------";
        cout<<"\nValor x aleatorio: "<<xAleatorio[i];
        cout<<"\nError aleatorio: "<<y;
        cout<<"\n--------------------------------------";
        */
        
        
        yAleatorio[i] = (1+y)*exp(-2*xAleatorio[i] + 1.5);
        yAleatorioLog[i] = log(yAleatorio[i]);
        cout<<"\n--------------------------------------";
        cout<<"\nx: "<<xAleatorio[i];
        cout<<"\ny: "<<yAleatorio[i];
        cout<<"\nlog y: "<<yAleatorioLog[i];
    }
    
    //  Ordenando numeros aleatorios
    double Dato1x, Dato2x;
    double Dato1y, Dato2y;
    double Dato1Logy, Dato2Logy;
    
    for (i = 0; i<(M - 1); i++)
    {
        for (j = i + 1; j<M; j++)
        {
            Dato1x = xAleatorio[i];
            Dato2x = xAleatorio[j];
            Dato1y = yAleatorio[i];
            Dato2y = yAleatorio[j];
            Dato1Logy = yAleatorioLog[i];
            Dato2Logy = yAleatorioLog[j];
            
            if (Dato2x<Dato1x)
            {
                xAleatorio[j] = Dato1x;
                xAleatorio[i] = Dato2x;
                yAleatorio[j] = Dato1y;
                yAleatorio[i] = Dato2y;
                yAleatorioLog[j] = Dato1Logy;
                yAleatorioLog[i] = Dato2Logy;
            }
        }
    }

    //  Imprimiendo numeros ordenados
    cout << "\n\n---------------------------------------------------------------";
    for (i = 0; i<M; i++)
    {
        cout<<"\n--------------------------------------";
        cout<<"\n i) "<<i;
        cout<<"\t\tValor x aleatorio: "<<xAleatorio[i];
        myfile<<xAleatorio[i]<<"\t"<<yAleatorio[i];
        myfile<<"\t"<<yAleatorioLog[i]<<"\n";
    }
    
    double S, Sx, Sy, Sxx, Sxy, Delta, a, b;
    S = M;
    Sx = 0;
    Sy = 0;
    Sxx = 0;
    Sxy = 0;
    Delta = 0;
    
    
    for (i = 0; i<M; i++)
    {
        Sx = Sx + xAleatorio[i];
        Sy = Sy + yAleatorioLog[i];
        Sxx = Sxx + pow(xAleatorio[i],2);
        Sxy = Sxy + xAleatorio[i]*yAleatorioLog[i];
    }
    
    cout<<"\n S: "<<S;
    
    Delta = S*Sxx - pow(Sx,2);
    a = (Sxx*Sy - Sx*Sxy)/Delta;
    b = (S*Sxy - Sx*Sy)/Delta;
    
    double sigmaA, sigmaB;
    sigmaA = sqrt(Sxx/Delta);
    sigmaB = sqrt(S/Delta);
    cout<<"\n\n Valor a (intercepto): "<<a<<" +- "<<sigmaA;
    cout<<"\n\n Valor b (pendiente): "<<b<<" +- "<<sigmaB;

    double ErrorY, ErrorLogY;
    
    for (i = 0; i<M; i++)
    {
        x = xAleatorio[i];
        y = exp(b*xAleatorio[i] + a);
        logy = b*xAleatorio[i] + a;
        ErrorY = exp(b*xAleatorio[i] + a)*sqrt( pow(sigmaA,2) + pow(b*sigmaB,2) );
        ErrorLogY = sqrt(pow(sigmaA,2) + pow(x*sigmaB,2));
        
        
        myfile1<<xAleatorio[i]<<"\t"<<exp(b*xAleatorio[i] + a);
        myfile1<<"\t"<<ErrorY;
        myfile1<<"\t"<<b*xAleatorio[i] + a<<"\t";
        myfile1<<ErrorLogY<<"\n";
        
        
        myfile2<<x<<"\t"<<logy<<"\t";
        myfile2<<logy - ErrorLogY;
        myfile2<<"\t"<<logy+ ErrorLogY<<"\n";
        
        myfile3<<x<<"\t"<<y<<"\t";
        myfile3<<y - ErrorY;
        myfile3<<"\t"<<y+ ErrorY<<"\n";
    }
    

    cout<<"\n\n";
	return 0;
}
