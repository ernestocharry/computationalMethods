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

	M = 50;             //  Numeros de No. aleatorio
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

	int N = 8;
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
	double pendiente, intercepto;

	for (j = 0; j<N; j++)
	{
		float NumDeseado = XNuevo[j];
		cout << "\n----------------------------------";
		cout << "\nNumero buscado: " << NumDeseado << "\n";

		int n0 = 0;
		int n1 = ceil(M - 1);
		int nMedio = ceil((n1 - n0) / 2);

		float NumMedio = VecAlt[nMedio];
		float distancia = NumDeseado - NumMedio;

		i = 0;
		while ((sqrt(distancia*distancia) > 0.01)) //  Valor absoluto
		{
			a = n0;
			b = n1;
			c = NumMedio;

			if (NumDeseado>NumMedio)
			{
				n0 = nMedio;
				nMedio = ceil((n0 + (n1 - n0) / 2));
				NumMedio = VecAlt[nMedio];
				distancia = NumDeseado - NumMedio;
			}

			if (NumDeseado<NumMedio)
			{
				n1 = nMedio;
				nMedio = ceil((n0 + (n1 - n0) / 2));
				NumMedio = VecAlt[nMedio];
				distancia = NumDeseado - NumMedio;
			}

			if (distancia == 0)
			{
				cout << "\n\nNumero encontrado en la posicion " << nMedio << "\n\n";
				// Hay que poner contador o if por si el valor que se quiere 
				// extrapolar se encuentra en los datos iniciales. 
			}

			i = i + 1;

			if (i == M)
			{
				distancia = 0;
				cout << "\n\nEl numero buscado No se encuentra en la lista.";
				cout << "\nLos numeros mas cercanos se encuentran en ";
				cout << "las posiciones " << nMedio << " y " << nMedio + 1;
				cout << "\nCorresponden a los numeros: " << VecAlt[nMedio];
				cout << " y " << VecAlt[nMedio + 1] << "\n\n";
			}

		}
		a = (FunAlt[nMedio + 1] - FunAlt[nMedio]);
		b = (VecAlt[nMedio + 1] - VecAlt[nMedio]);
		pendiente = a / b;
		intercepto = FunAlt[nMedio] - pendiente * VecAlt[nMedio];

		YNuevo[j] = pendiente * XNuevo[j] + intercepto;
		Diferencia[j] = (2 * sin(XNuevo[j]) + cos(2 * XNuevo[j])) - YNuevo[j];

		cout << "\n j: " << j;
		cout << "\n nMedio: " << nMedio;
		cout << "\n VecAlt[nMedio]: " << VecAlt[nMedio];
		cout << "\n FunAlt[nMedio]: " << FunAlt[nMedio];
		cout << "\n VecAlt[nMedio+1]: " << VecAlt[nMedio + 1];
		cout << "\n FunAlt[nMedio+1]: " << FunAlt[nMedio + 1];
		cout << "\n XNuevo[j]: " << XNuevo[j];
		cout << "\n YNuevo[j]: " << YNuevo[j];
		cout << "\n Diferencia en Y: " << Diferencia[j];

	}
	cout << "\n-----------------------------------------------------------------";
	//--------------------------------------------------------------------------

	cout<<"\n-----------------------------------------------------------------";
    cout<<"\n\nRESULTADOS\n";
    
	for (i = 0; i<N; i++)
	{
		a = 2 * sin(XNuevo[i]) + cos(2 * XNuevo[i]);
		cout << "\n----------------------------------------";
		cout << "\n Valor i: " << i;
		cout << "\n Valor XNuevo[i]: " << XNuevo[i];
		cout << "\n Resultado Aprox. Lineal, YNuevo[i]: " << YNuevo[i];
		cout << "\n Funcion Original evaluada en XNuevo[i]: " << a;
	}
	cout << "\n-----------------------------------------------------------------\n\n";

	return 0;
}

