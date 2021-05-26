#include <iostream>
#include <time.h>

#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    cout<<"\n\n---------------------------------------------------------------";
	cout<<"\nInicio programa";
	cout<<"\n\t\tCubic Spline Interpolation";
	cout<<"\n\t\t";
	
	int i, j, k, m;

    // Lo conocido 
	int N = 200;             //  Numeros de No. en el intervalo 
	double x0 = 0;      //  Limites del intervalo
	double x1 = 5;
	
	double DeltaX = (x1-x0)/(N-1);

    double VecX[N];         // Valores en X donde se conoce la funcion 
    double VecY[N];         // Valores en Y en donde se conoce la funcion 

    // En donde se quiere conocer 
    int M = 50; 
	double xAleatorio[M];   //  Vector X en donde se quiere calcular la funcion 
	double yAleatorio[M];   //  Vector Y desconocido
	
	double ValorAlt;    //  Utilizado para guardar datos aleatorio

    //--------------------------------------------------------------------------
    //  Generando datos en el intervalo de igual de espaciado
    cout<<"\ni\tValor X\tValorY\n"; 
	for (i = 0; i<N; i++)
	{
	    VecX[i] = DeltaX*i + x0; 
	    VecY[i] = 2*sin(VecX[i]) + cos(2*VecX[i]);
	    cout<<"\n"<<i<<"\t"<<VecX[i]; 
	}

	int NN = N-2; 
	double MatrixPol[NN][NN+1];
    double L[NN][NN+1];
    
    cout<<"\n-----------------------------------------------------------------";
    cout<<"\nComenzando solucion de sistema N-2"; 
    
    // Asignando valores a la matriz MatrixPol que es de tipo Vandermode
    for (i = 0; i<NN; i++)
    {
        for (j = 0; j<NN; j++)
	    {
	        if(i==j) MatrixPol[i][j] = 4; 
	        else if((i-j)==1 || (j-i)==1)    MatrixPol[i][j] = 1; 
	        else MatrixPol[i][j] = 0; 
	    }
	    MatrixPol[i][NN] = (VecY[i] - 2*VecY[i+1] + VecY[i+2])*6/(DeltaX*DeltaX);    // Revisar. Ver Libro. 
    }
	
	
	cout<<"\n-----------------------------------------------------------------";
    cout<<"\nInicio de Metodo de  Gauss-Jordan------------------------------\n";
    int p;
  
    double a,b,c, v, y;

    for (i = 0; i < NN; i++)
    {
        cout << "\n";
        for (j = 0; j <= NN; j++)
	    {
//	    cout << " " << MatrixPol[i][j];
	    }
    }

    // Proceso diagonalizacion matriz triangular superior 
    for (p = 0; p < NN; p++)
    {
        for (i = p; i < NN; i++)
	    {
	        if (i == p)
	        {
	            v = MatrixPol[i][i];
	            for (j = p; j <=NN; j++)
		        {
		            y = MatrixPol[i][j];
		            MatrixPol[i][j] = y / v;
		        }
	        }
	        if (i > p)
	        {
	            a = MatrixPol[i][p];
	            for (j = p; j <= NN; j++)
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
    for (i = 0; i < NN; i++)
    {
        L[i][NN] = MatrixPol[NN-1-i][NN]; 
        for(j=0;j<NN;j++)
        {
            L[i][j] = MatrixPol[NN-1-i][NN-1-j];
        }
    }

    // Proceso diagonalizacion de matriz triangular inferior 
    for (p = 0; p < NN; p++)
    {
        for (i = p; i < NN; i++)
	    {
	        if (i == p)
	        {
	            v = L[i][i];
	            for (j = p; j <=NN; j++)
		        {
		            y = L[i][j];
		            L[i][j] = y / v;
		        }
	        }
	        if (i > p)
	        {
	            a = L[i][p];
	            for (j = p; j <= NN; j++)
		        {
		            b = L[i][j];
		            c = L[p][j];
		            L[i][j] = b - a * c;
		        }
	        }
	    }
    }
    
    cout << "\n";
    for (i = 0; i < NN; i++)
    {
        cout << "\n";
        for (j = 0; j <= NN; j++)
	    {
//	    cout << " " << L[i][j];
	    }
    }
    
    cout<<"\n-----------------------------------------------------------------";
    cout<<"\nFin de Metodo de  Gauss-Jordan------------------------------\n";


		
//*************************** Se UTILIZARA DESPUES ****************************	
	cout<<"\n Nuevos Numeros aleatorios\n";
	// Generando valores aleatorios de x para calcular la funcion 
		for (i = 0; i<M; i++)
	{
		ValorAlt = (double)rand() / double(RAND_MAX);
		srand(time(NULL) + rand());
		xAleatorio[i] = (x1 - x0)*ValorAlt + x0;

	}
	// Ordenando los valores anteriores 
	
	double Dato1x, Dato2x; 
	
	for (i = 0; i<(M - 1); i++)
	{
		for (j = i + 1; j<M; j++)
		{
			Dato1x = xAleatorio[i];
			Dato2x = xAleatorio[j];
			if (Dato2x<Dato1x)
			{
				xAleatorio[j] = Dato1x;
				xAleatorio[i] = Dato2x;
			}
		}
	}
	
	cout<<"\n Numeros ordenados\n";
	for (i = 0; i<M; i++)
	{
 //       cout<<"\n"<<xAleatorio[i]; 
	}
//*****************************************************************************
    // Es necesario buscar en donde cae los nuevos numeros aleatorios 

    cout<<"\n-----------------------------------------------------------------";
	cout<<"\nBuscando valores cercanos de X en la lista, ";
	cout<<"\nposteriormente se calcula regresion lineal entre los dos ";
	cout<<"\npuntos mas cercanos.";

    double Aprox; 
    double Real; 
    double ErrorRelativo; 
    
    double a0, a1, a2, a3; 
    
    
    ofstream myfile;
    myfile.open ("example.txt");

    for(j=0; j<M; j++)
    {
        float NumDeseado = xAleatorio[j];
        cout << "\n----------------------------------";
        cout<<"\nNumero buscado: "<<NumDeseado<<"\n";
    
        int n0 = 0;
        int n1 = ceil(N-1);
        int nMedio = ceil((n1-n0)/2);

        float NumMedio = VecX[nMedio];
        float distancia = NumDeseado - NumMedio;

        i = 0;
        while( (sqrt(distancia*distancia) > 0.01) ) //  Valor absoluto
        {
            a = n0;
            b = n1;
            c = NumMedio;
        
            if(NumDeseado>NumMedio)
            {
                n0 = nMedio;
                nMedio = ceil((n0+(n1-n0)/2));
                NumMedio = VecX[nMedio];
                distancia = NumDeseado - NumMedio;
            }
        
            if(NumDeseado<NumMedio)
            {
            n1 = nMedio;
            nMedio = ceil((n0+(n1-n0)/2));
            NumMedio = VecX[nMedio];
            distancia = NumDeseado - NumMedio;
            }
        
            if(distancia==0)
            {
            cout<<"\n\nNumero encontrado en la posicion "<<nMedio<<"\n\n";
            // Hay que poner contador o if por si el valor que se quiere 
            // extrapolar se encuentra en los datos iniciales. 
            }
        
            i=i+1;
        
            if(i==N)
            {
            distancia = 0;
            cout<<"\n\nEl numero buscado No se encuentra en la lista.";
            cout<<"\nLos numeros mas cercanos se encuentran en ";
            cout<<"las posiciones "<<nMedio<<" y "<<nMedio+1;
            cout<<"\nCorresponden a los numeros: "<<VecX[nMedio];
            cout<<" y "<<VecX[nMedio+1]<<"\n\n";
            }
            
        }
        
        a0 = VecY[nMedio]; 
        a1 = (VecY[nMedio+1] - VecY[nMedio])/DeltaX - (L[NN-1-nMedio+1][NN] + 2*L[NN-1-nMedio][NN])*DeltaX/6; 
        a2 = L[NN-1-nMedio][NN]/2; 
        a3 = (L[NN-1-nMedio+1][NN] - L[NN-1-nMedio][NN])/(6*DeltaX); 
        
        Aprox = a0 + a1*(NumDeseado- VecX[nMedio]) + a2*pow(NumDeseado- VecX[nMedio],2) + a3*pow(NumDeseado- VecX[nMedio],3); 
        Real = 2*sin(NumDeseado) + cos(2*NumDeseado); 
        ErrorRelativo = sqrt(pow(1- Aprox/Real,2)) ; 
        
        cout<<"\n "<<j<<") Resultado para x = "<< NumDeseado; 
        cout<<"\n Interpolacion: "<<Aprox; 
        cout<<"\n Valor exacto funcion: "<< Real ; 
        cout<<"\n Error relativo = "<<ErrorRelativo; 
        
        // Escribiendo en archivo 
        myfile<<"\n"<<NumDeseado; 
        myfile<<"\t"<<Aprox;
        myfile<<"\t"<<Real;
        myfile<<"\t"<<ErrorRelativo;

        
    }
    cout<<"\n-----------------------------------------------------------------";
    
    myfile.close();
    

	return 0; 
}

