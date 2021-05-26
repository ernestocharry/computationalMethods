#include <iostream>
#include <time.h>

#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    cout<<"\nCubic Spline Interpolation";
	
	int i, j, k, m;

    // Lo conocido 
	int N = 37;             //  Numeros de No. en el intervalo
    double VecX[N], VecY[N], Z[N], T[N];    // Valores en X donde se conoce la funcion
    
    double x0 = 0;      //  Limites del intervalo
    double x1 = 1.022000;
    double DeltaX = (x1-x0)/(N-1);

    
    VecX[0]=	0.001000	;VecY[0]=	0.0061860	;Z[0]=	1887	;T[0]=	1887.0	;
    VecX[1]=	0.001103	;VecY[1]=	0.0072300	;Z[1]=	1495	;T[1]=	1495.0	;
    VecX[2]=	0.001217	;VecY[2]=	0.0084270	;Z[2]=	1185	;T[2]=	1185.0	;
    VecX[3]=	0.001217	;VecY[3]=	0.0084270	;Z[3]=	4356	;T[3]=	4356.0	;
    VecX[4]=	0.001232	;VecY[4]=	0.0085910	;Z[4]=	4651	;T[4]=	4651.0	;
    VecX[5]=	0.001248	;VecY[5]=	0.0087580	;Z[5]=	4966	;T[5]=	4966.0	;
    VecX[6]=	0.001248	;VecY[6]=	0.0087580	;Z[6]=	6650	;T[6]=	6650.0	;
    VecX[7]=	0.001328	;VecY[7]=	0.0096220	;Z[7]=	6074	;T[7]=	6074.0	;
    VecX[8]=	0.001414	;VecY[8]=	0.0105400	;Z[8]=	5549	;T[8]=	5549.0	;
    VecX[9]=	0.001414	;VecY[9]=	0.0105400	;Z[9]=	6282	;T[9]=	6282.0	;
    VecX[10]=	0.001500	;VecY[10]=	0.0114500	;Z[10]=	5470	;T[10]=	5470.0	;
    VecX[11]=	0.002000	;VecY[11]=	0.0166500	;Z[11]=	2706.000	;T[11]=	2706.0	;
    VecX[12]=	0.003000	;VecY[12]=	0.02603000	;Z[12]=	957.100	;T[12]=	957.1	;
    VecX[13]=	0.004000	;VecY[13]=	0.0342200	;Z[13]=	446.100	;T[13]=	446.2	;
    VecX[14]=	0.005000	;VecY[14]=	0.0416800	;Z[14]=	244.100	;T[14]=	244.10	;
    VecX[15]=	0.006000	;VecY[15]=	0.0485700	;Z[15]=	148.100	;T[15]=	148.20	;
    VecX[16]=	0.008000	;VecY[16]=	0.0607800	;Z[16]=	66.750	;T[16]=	66.81	;
    VecX[17]=	0.010000	;VecY[17]=	0.0711500	;Z[17]=	35.710	;T[17]=	35.78	;
    VecX[18]=	0.011100	;VecY[18]=	0.0761400	;Z[18]=	26.590	;T[18]=	26.67	;
    VecX[19]=	0.011100	;VecY[19]=	0.0761400	;Z[19]=	196.600	;T[19]=	196.70000	;
    VecX[20]=	0.015000	;VecY[20]=	0.0904900	;Z[20]=	90.400	;T[20]=	90.49000	;
    VecX[21]=	0.020000	;VecY[21]=	0.1027000	;Z[21]=	41.440	;T[21]=	41.54000	;
    VecX[22]=	0.030000	;VecY[22]=	0.1161000	;Z[22]=	13.350	;T[22]=	13.47000	;
    VecX[23]=	0.040000	;VecY[23]=	0.1223000	;Z[23]=	5.843	;T[23]=	5.96500	;
    VecX[24]=	0.050000	;VecY[24]=	0.124800	;Z[24]=	3.044	;T[24]=	3.16900	;
    VecX[25]=	0.060000	;VecY[25]=	0.125400	;Z[25]=	1.775000	;T[25]=	1.90000	;
    VecX[26]=	0.080000	;VecY[26]=	0.123900	;Z[26]=	0.751500	;T[26]=	0.87540	;
    VecX[27]=	0.100000	;VecY[27]=	0.121000	;Z[27]=	0.383500	;T[27]=	0.50450	;
    VecX[28]=	0.150000	;VecY[28]=	0.112500	;Z[28]=	0.112500	;T[28]=	0.22500	;
    VecX[29]=	0.200000	;VecY[29]=	0.104800	;Z[29]=	0.047320	;T[29]=	0.15210	;
    VecX[30]=	0.300000	;VecY[30]=	0.092310	;Z[30]=	0.014370	;T[30]=	0.10670	;
    VecX[31]=	0.400000	;VecY[31]=	0.083190	;Z[31]=	0.006412	;T[31]=	0.08960	;
    VecX[32]=	0.500000	;VecY[32]=	0.076200	;Z[32]=	0.003541	;T[32]=	0.07974	;
    VecX[33]=	0.600000	;VecY[33]=	0.070630	;Z[33]=	0.002238	;T[33]=	0.07287	;
    VecX[34]=	0.800000	;VecY[34]=	0.062180	;Z[34]=	0.001144	;T[34]=	0.06332	;
    VecX[35]=	1.000000	;VecY[35]=	0.055960	;Z[35]=	0.000712	;T[35]=	0.05667	;
    VecX[36]=	1.022000	;VecY[36]=	0.055370	;Z[36]=	0.00067660	;T[36]=	0.05605	;
    

    //--------------------------------------------------------------------------
    //  Generando datos en el intervalo de igual de espaciado
    
	int NN = N-2; 
	double MatrixPol[NN][NN+1];
    double L[NN][NN+1];
    
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
	
    cout<<"\nInicio de Metodo de  Gauss-Jordan------------------------------";
    int p;
  
    double a,b,c, v, y;

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

    cout<<"\nFin de Metodo de  Gauss-Jordan------------------------------";


//*****************************************************************************
// Es necesario buscar en donde cae los nuevos numeros aleatorios

    double Aprox;
    double a0, a1, a2, a3; 
    
    float NumDeseado = 0.81;
    
    int n0 = 0;
    int n1 = ceil(N-1);
    int nMedio = ceil((n1-n0)/2);

    float NumMedio = VecX[nMedio];
    float distancia = NumDeseado - NumMedio;

    i = 0;
    while( (sqrt(distancia*distancia) > 0.001) ) //  Valor absoluto
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
        
        if(distancia==0)    cout<<"\n\nNumero encontrado en la posicion "<<nMedio<<"\n\n";
        i=i+1;
        if(i==N)            distancia = 0;

    }

    a0 = VecY[nMedio];
    a1 = (VecY[nMedio+1] - VecY[nMedio])/DeltaX - (L[NN-1-nMedio+1][NN] + 2*L[NN-1-nMedio][NN])*DeltaX/6;
    a2 = L[NN-1-nMedio][NN]/2;
    a3 = (L[NN-1-nMedio+1][NN] - L[NN-1-nMedio][NN])/(6*DeltaX);
        
    Aprox = a0 + a1*(NumDeseado- VecX[nMedio]) + a2*pow(NumDeseado- VecX[nMedio],2) + a3*pow(NumDeseado- VecX[nMedio],3);
        
    cout<<"\nResultado para E = "<< NumDeseado <<" keV \t Interpolacion: "<<Aprox;
    cout<<"\n\n";
    
	return 0; 
}

