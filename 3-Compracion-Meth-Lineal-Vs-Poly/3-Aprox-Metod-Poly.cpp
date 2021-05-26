//  Universidad Nacional Autonoma de Mexico
//  Posgrado en Ciencias Fisicas
//  Introduccion a la Fisica Computacional 
//  Profesor: Santiago Francisco Caballero Benitez
//  Autor: F. E. Charry-Pastrana 
//  13.02.2018

#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

int main()
{
	cout << "\n\n---------------------------------------------------------------";
	cout << "\nInicio programa";
	cout << "\n\t\tFinalidad: comprobar metodo de aproximacion lineal";
	cout << "\n\t\tvs. aproximacion utilizando polinomio.";

	int i, j, M;

	M = 15;             //  Numeros de No. aleatorio
	int n0Alt = 0;      //  Limites del intervalo
	int n1Alt = 5;

	double VecAlt[M];   //  Vector Aleatorio
	double FunAlt[M];   //  Calculo de la funcion en los puntos de VecAlt
	double ValorAlt;    //  Utilizado para guardar datos aleatorio

						//--------------------------------------------------------------------------
						//  Generando datos aleatorios
	for (i = 0; i<M; i++)
	{
		ValorAlt = (double)rand() / double(RAND_MAX);
		srand(time(NULL) + rand());
		VecAlt[i] = (n1Alt - n0Alt)*ValorAlt + n0Alt;
		//		cout << VecAlt[i] << "\n";
		FunAlt[i] = 2 * sin(VecAlt[i]) + cos(2 * VecAlt[i]);

	}
	//--------------------------------------------------------------------------

	double Dato1x, Dato2x;
	double Dato1y, Dato2y;
	//--------------------------------------------------------------------------
	//  Ordenando los datos aleatorios, tarea anterior
	for (i = 0; i<(M - 1); i++)
	{
		for (j = i + 1; j<M; j++)
		{
			Dato1x = VecAlt[i];
			Dato2x = VecAlt[j];
			Dato1y = FunAlt[i];
			Dato2y = FunAlt[j];
			if (Dato2x<Dato1x)
			{
				VecAlt[j] = Dato1x;
				VecAlt[i] = Dato2x;
				FunAlt[j] = Dato1y;
				FunAlt[i] = Dato2y;
			}
		}
	}
	//--------------------------------------------------------------------------
	//  Escribiendo los datos aleatorios generados en la  terminal
	cout << "\n\n---------------------------------------------------------------";
	cout << "\n" << M << " datos aleatorios generador ordenados";
	cout << "\nPosicion\tDato en X\tDato en Y\n";
	for (i = 0; i<M; i++)
	{
		cout << "\n" << i << "\t" << VecAlt[i] << "\t" << FunAlt[i];
	}
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//  Los vectores VecAlt y FunAlt ya se encuentran ordenados. 
	//  Ahora es necesario:
	//      1)  Definir nuevos N puntos aleatorios 
	//      2)  Extrapolar el valor de la funcion utilizando regresion
	//          lineal 
	//      3)  Ajustar un polinomio de orden M-1 con los vectores 
	//          VecAlt y FunAlt utilizando la solucion de sistemas lineales 
	//          mediante Metodo de GaussJordan
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
	//  Generando nuevos N numeros aleatorios en determinado intervalo.

	int N = 18;
	int n0Nuevo = 0;
	int n1Nuevo = ceil((n1Alt * 1));
	double XNuevo[N];
	double YNuevo[N];
	double Diferencia[N];

	cout << "\n\n---------------------------------------------------------------";
	cout << "\nDatos de Nuevos Aleatorios Nuevos:";
	cout << "\n Numero de datos: " << N;
	cout << "\n Intervalo: " << n0Nuevo << " hasta " << n1Nuevo;
	cout << "\n-----------------------------------------------------------------";

	//  Calculando numeros aleatorios:    
	cout << "\n\nNuevos Numeros X\n\n";
	for (i = 0; i<N; i++)
	{
		ValorAlt = (double)rand() / double(RAND_MAX);
		srand(time(NULL) + rand());
		XNuevo[i] = (n1Nuevo - n0Nuevo)*ValorAlt + n0Nuevo;
		cout << XNuevo[i] << "\n";
	}
	//  Ordenandolos:
	for (i = 0; i<(N - 1); i++)
	{
		for (j = i + 1; j<N; j++)
		{
			Dato1x = XNuevo[i];
			Dato2x = XNuevo[j];

			if (Dato2x<Dato1x)
			{
				XNuevo[j] = Dato1x;
				XNuevo[i] = Dato2x;
			}
		}
	}
	//  Mostrar nuevos numeros aleatorios ordenados 
	cout << "\n-----------------------------------------------------------------";
	cout << "\n\nX Nuevo Ordenado\t Funcion de estos puntos\n\n";
	for (i = 0; i<N; i++)
	{
		cout << XNuevo[i] << "\t" << 2 * sin(XNuevo[i]) + cos(2 * XNuevo[i]) << "\n";
	}
	cout << "\n-------------------------------------------------------------\n\n";
	//--------------------------------------------------------------------------
	//  Encontrar los valores cercanos de X nuevos valores entre
	//  los primeros M valores aleatorios encontrados para realizar 
	//  ajuste lineal entre estos dos datos
	cout << "\n-----------------------------------------------------------------";
	cout << "\nBuscando valores cercanos de X en la lista, ";
	cout << "\nposteriormente se calcula regresion lineal entre los dos ";
	cout << "\npuntos mas cercanos.";
	double a, b, c;

	cout << "\n-----------------------------------------------------------------";
	//--------------------------------------------------------------------------
	//  Comienza el metodo de ajuste de polinomio de los M datos
	double MatrixPol[M][M + 1];
	double L[M][M + 1];

	cout << "\n-----------------------------------------------------------------";
	cout << "\nComenzando el metodo de ajuste de polinomio de orden M-1.";

	// Asignando valores a la matriz MatrixPol que es de tipo Vandermode
	for (i = 0; i<M; i++)
	{
		for (j = 0; j<M; j++)
		{
			MatrixPol[i][j] = pow(VecAlt[i], j);
		}
		MatrixPol[i][M] = FunAlt[i];
	}
	// Imprimiendo matriz 
	cout << "\n-----------------------------------------------------------------";
	//    for (i = 0; i<M; i++)
	//    {
	//        cout << "\n";
	//        for (j = 0; j< M+1; j++)
	//	    {
	//	        cout << " " << MatrixPol[i][j];
	//	    }
	//    }
	cout << "\n-----------------------------------------------------------------";
	//--------------------------------------------------------------------------
	//  Comienza el metodo de GaussJordan (tarea 1) para la solucion 
	//  del sistema lineal y encontrar los coeficientes M-1 
	cout << "\n-----------------------------------------------------------------";
	cout << "\nInicio de Metodo de  Gauss-Jordan------------------------------\n";
	int p;
	double v, y;

	// Proceso diagonalizacion matriz triangular superior 
	for (p = 0; p < M; p++)
	{
		for (i = p; i < M; i++)
		{
			if (i == p)
			{
				v = MatrixPol[i][i];
				for (j = p; j <= M; j++)
				{
					y = MatrixPol[i][j];
					MatrixPol[i][j] = y / v;
				}
			}
			if (i > p)
			{
				a = MatrixPol[i][p];
				for (j = p; j <= M; j++)
				{
					b = MatrixPol[i][j];
					c = MatrixPol[p][j];
					MatrixPol[i][j] = b - a * c;
				}
			}
		}
	}

	//  Imprimiendo matriz despues de proceso de diagonalizacion superior
	//    for (i = 0; i < M; i++)
	//    {
	//        cout << "\n";
	//        for (j = 0; j <= M; j++)
	//	    {
	//	    cout << " " << MatrixPol[i][j];
	//	    }
	//    }

	//  Ubicando matriz diagonal superior en matriz diagonal
	for (i = 0; i < M; i++)
	{
		L[i][M] = MatrixPol[M - 1 - i][M];
		for (j = 0; j<M; j++)
		{
			L[i][j] = MatrixPol[M - 1 - i][M - 1 - j];
		}
	}

	// Proceso diagonalizacion de matriz triangular inferior 
	for (p = 0; p < M; p++)
	{
		for (i = p; i < M; i++)
		{
			if (i == p)
			{
				v = L[i][i];
				for (j = p; j <= M; j++)
				{
					y = L[i][j];
					L[i][j] = y / v;
				}
			}
			if (i > p)
			{
				a = L[i][p];
				for (j = p; j <= M; j++)
				{
					b = L[i][j];
					c = L[p][j];
					L[i][j] = b - a * c;
				}
			}
		}
	}

	// Imprimiendo matriz diagonalizada
	//    for (i = 0; i < M; i++)
	//    {
	//        cout << "\n";
	//        for (j = 0; j <= M; j++)
	//	    {
	//	    cout << " " << L[i][j];
	//	    }
	//    }
	cout << "\n-----------------------------------------------------------------";
	cout << "\nResultados de los coeficientes del polinomio de orden M-1: ----\n";

	for (i = 0; i<M; i++)
	{
		cout << "\nEl coeficiente a_" << i << " es igual a " << L[M - i - 1][M];
	}
	cout << "\n-----------------------------------------------------------------";
	// Cuidado, ¡los coeficientes NO se encuentran ordenados!

	cout << "\n-----------------------------------------------------------------";
	cout << "\nComprobando los resultados del polinomio de orden M -1 para";
	cout << "\nlos primeros 6 numeros\n";
	double ResulPol[200];   //  El tamano del vector es para no problemas.  

	for (i = 0; i<M; i++)
	{
		ResulPol[i] = 0;
		for (j = 0; j<M; j++)
		{
			ResulPol[i] = ResulPol[i] + (pow(VecAlt[i], j))*L[M - j - 1][M];
		}
		if (i<6)
		{
			cout << "\n i:" << i;
			cout << "\n VecAlt[i]: " << VecAlt[i];
			cout << "\n FunAlt[i]: " << FunAlt[i];
			cout << "\n ResulPolinomio[i]: " << ResulPol[i];
		}
	}
	cout << "\n-----------------------------------------------------------------";

	cout << "\n-----------------------------------------------------------------";
	cout << "\nCalculando el valor de la funcion utilizando el polinomio \n";
	cout << "\nextrapolado en los nuevos X puntos.\n";
	//  Mucho cuidado con los indices
	for (i = 0; i<N; i++)
	{
		ResulPol[i] = 0;
		for (j = 0; j<M; j++)
		{
			ResulPol[i] = ResulPol[i] + (pow(XNuevo[i], j))*L[M - j - 1][M];
		}
	}

	cout << "\n-----------------------------------------------------------------";
	cout << "\nComprobando dos metodos en " << N << " puntos";
	cout << "\n\ta) ajuste lineal entre los dos puntos mas cercanos,";
	cout << "\n\tb) utilizando polinomio extrapolado de orden M-1.\n\n";

	for (i = 0; i<N; i++)
	{
		a = 2 * sin(XNuevo[i]) + cos(2 * XNuevo[i]);
		cout << "\n----------------------------------------";
		cout << "\n Valor i: " << i;
		cout << "\n Valor XNuevo[i]: " << XNuevo[i];
		cout << "\n Resultado Polinomio de orden M-1, ResulPol[i]: " << ResulPol[i];
		cout << "\n Funcion Original evaluada en XNuevo[i]: " << a;
	}
	cout << "\n-----------------------------------------------------------------";

	return 0;
}

