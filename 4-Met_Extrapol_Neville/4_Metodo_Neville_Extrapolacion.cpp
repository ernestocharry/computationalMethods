//  Universidad Nacional Autonoma de Mexico
//  Posgrado en Ciencias Fisicas 
//  Introduccion a la Fisica Computacional 
//  Profesor: Santiago Caballero
//  Autor: F. E. Charry-Pastrana
//  201802015

//  Metodo de Neville. Ref: Numerical Recp

#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

int main()
{
	cout << "\n Inicio del programa: extrapolacion por Meth. Neville";
	int i, j, k;
	double a, b, c, d;

	int N = 20;     // No. de puntos.
	double x0 = 0;     // Limites en X
	double x1 = 10;    //

    int NPrueba = 10;
	double ValorX[NPrueba][2];       // Valor de la funcion a extrapolar en limites de X

	double print = 0;       // Para mostrar print = 1

	double VecQ[N][N], VecX[N]; // Para guardar datos.
								// Generando N puntos aleatorios en el intervalo

								//-------------------------------------------------------------------------
								//  Inicializando en ceros
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			VecQ[i][j] = 0;
		}
	}
	cout << "\n Se asigno valores iniciales nulos";
	//-------------------------------------------------------------------------
	// Asignando valores aleatorios en el intervalo     
	for (i = 0; i<N; i++)
	{
		a = (double)rand() / double(RAND_MAX);
		srand(time(NULL) + rand());
		VecX[i] = (x1 - x0)*a + x0;
		//        VecX[i] = (x1-x0)*i/N + x0;   // Intervalo controlado. 
		// Comprar proceso con Excel

		//  Funcion REAL = 2*sin(VecX[i]) + cos(2*VecX[i])
		VecQ[i][0] = 2 * sin(VecX[i]) + cos(2 * VecX[i]);

	}
    
    for (i = 0; i<NPrueba; i++)
    {
        a = (double)rand() / double(RAND_MAX);
        srand(time(NULL) + rand());
        ValorX[i][0] = (x1 - x0)*a + x0;
    }
    
    
	cout << "\n Se asigno valores aleatorios en el intervalo";

	// ORdenando los puntos
	for (i = 0; i<(N - 1); i++)
	{
		for (j = i + 1; j<N; j++)
		{
			a = VecX[i];
			b = VecX[j];
			c = VecQ[i][0];
			d = VecQ[j][0];
			if (b<a)
			{
				VecX[j] = a;
				VecX[i] = b;
				VecQ[j][0] = c;
				VecQ[i][0] = d;
			}
		}
	}
    
    for (i = 0; i<(NPrueba - 1); i++)
    {
        for (j = i + 1; j<NPrueba; j++)
        {
            a = ValorX[i][0];
            b = ValorX[j][0];
            if (b<a)
            {
                ValorX[j][0] = a;
                ValorX[i][0] = b;

            }
        }
    }
    
	cout << "\n Se ordeno valores en el intervalo";
	cout << "\n\n\n Iniciando proceso Metodo Neville";
	double xx1, xx2;

    for(k=0; k<NPrueba; k++)
    {
	for (j = 1; j<N; j++)
	{
		if (print == 1)
		{
			cout << "\n---------------------------------------------------------";
		}
		for (i = j; i<N; i++)
		{

			a = VecQ[i - 1][j - 1];
			b = VecQ[i][j - 1];

			xx1 = VecX[i - j];
			xx2 = VecX[i];

			VecQ[i][j] = ((ValorX[k][0] - xx1)*b - (ValorX[k][0] - xx2)*a) / (-xx1 + xx2);
            ValorX[k][1] = VecQ[i][j];
			if (print == 1)
			{
				cout << "\n-----------------------------------";
				cout << "\n i: " << i;
				cout << "\n j: " << j;
				cout << "\n VecX[i-j]: " << xx1;
				cout << "\n VecX[i]: " << xx2;
				cout << "\n a: " << a;
				cout << "\n b: " << b;
				cout << "\nValor de Q[i][j]: " << VecQ[i][j];
				cout << "\n-----------------------------------";
			}
		}
	}
    }
	cout << "\n Proceso Metodo Neville completado\n";

	//--------------------------------------------------------------------------
	//  Imprimiendo Proceso 
	if (print == 1)
	{
		for (i = 0; i<N; i++)
		{
			cout << "\n\t" << VecX[i] << " | \t";
			for (j = 0; j<N; j++)
			{
				cout << "\t" << VecQ[i][j];
			}


		}
	}
	//--------------------------------------------------------------------------
    for(k=0; k<NPrueba; k++)
    {
	cout << "\n\n Resultados. \n";
	cout << "\n\tValor X en donde se realizo extrapolacion: " << ValorX[k][0];
	cout << "\n\tValor Y calculado en X mediante funcion: " << 2 * sin(ValorX[k][0]) + cos(2 * ValorX[k][0]);
	cout << "\n\tValor Y calculado en X mediante extrapolacion: " << ValorX[k][1];
	cout << "\n\tDiferencia en Y: " <<  2* sin(ValorX[k][0]) + cos(2 * ValorX[k][0]) - ValorX[k][1];
	cout << "\n\n";
    }
    //--------------------------------------------------------------------------
    cout << "\n\n Resultados tabla. \n";
    cout << "\n\n k \t\t X \t\t Funcion(X) \t\t Interpolado \t\t Diferencia\n\n";
    for(k=0; k<NPrueba; k++)
    {
        cout << k <<"\t\t"<< ValorX[k][0] <<"\t\t";
        cout << 2 * sin(ValorX[k][0]) + cos(2 * ValorX[k][0])<<"\t\t";
        cout << ValorX[k][1] <<"\t\t";
        cout << 2* sin(ValorX[k][0]) + cos(2 * ValorX[k][0]) - ValorX[k][1];
        cout << "\n\n";
    }
    
    
	return 0;
}
