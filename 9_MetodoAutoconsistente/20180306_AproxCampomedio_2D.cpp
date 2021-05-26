#include <iostream>
#include <time.h>
#include <fstream>
#include <math.h>
#include <armadillo>

using namespace std;
using namespace arma;

const int n = 5;
double OperadorB[n+1][n+1];   
double OperadorBDaga[n+1][n+1]; 
double OperadorN[n+1][n+1];
double OperadorN2[n+1][n+1];
double OperadorIdentidad[n+1][n+1];
double OperadorHEfectivo[n+1][n+1];

double EigenVectorsReales[n+1][n+1];
double EigenVectorsImag[n+1][n+1];
double EigenValues[n+1];
double EigenValueMin;
int PositionEigenValue;

void DefinirOperadores(); 
void Imprimir(double Matrix[n+1][n+1]);
void CalculandoHEfectivo(double Psi, double x, double mu);
void CalculandoEigen();
double CalculandoNuevoPsi();
double CalculandoRho();
double CalculandoRho2();
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
int main()
{
    int i,j,k;
    int InterationsMax;
    double Psi0, PsiAnterior;
    double u, mu;
    double ErrorLimit, ErrorDiferencia;
    
    ofstream myfile1, myfile2, myfile3, myfile4;
    myfile1.open ("AproxCampoMedio2D_x_Psi.txt");
    myfile2.open ("AproxCampoMedio2D_x_Rho.txt");
    myfile3.open ("AproxCampoMedio2D_x_Rho2.txt");
    myfile4.open ("AproxCampoMedio2D_x_Diferencia_Rho2_RhoRho.txt");

    DefinirOperadores();
    
    cout<<"\n Operador N:";
    Imprimir(OperadorN);
    cout<<"\n Operador N2:";
    Imprimir(OperadorN2);
    cout<<"\n Operador B:";
    Imprimir(OperadorB);
    cout<<"\n Operador BDaga:";
    Imprimir(OperadorBDaga);
    cout<<"\n Operador Identidad:";
    Imprimir(OperadorIdentidad);
    
    InterationsMax = 1000;
    ErrorLimit = pow(10,-5);
    
    double x;
    double xMin= pow(10,-3);
    double xMax =0.5;
    int xN = 500;
    double xDelta = (xMax-xMin)/xN;
    
    double Rho;
    double Rho2;
    
    for(i=0; i<=xN; i++)
    {
        x =xDelta*i + xMin;
        mu = 0.5/x;

        Psi0    =   0.1;
        PsiAnterior = Psi0 + 10;
        
        k=0;
        ErrorDiferencia = sqrt((PsiAnterior-Psi0)*(PsiAnterior-Psi0));
        
        while((k<InterationsMax) && ErrorDiferencia>ErrorLimit)
        {

            CalculandoHEfectivo(Psi0,x,mu);
            CalculandoEigen();
            
            Psi0 = CalculandoNuevoPsi();
            if(Psi0>20) Psi0 = 0.01;
            ErrorDiferencia = sqrt((PsiAnterior-Psi0)*(PsiAnterior-Psi0));
                
            if((k+1)==InterationsMax)
            {
                cout<<"\n Psi0 NO convergue.\tx: "<<x<<"\tmu: "<<mu;
            }
            if(ErrorDiferencia<ErrorLimit)
            {
                Rho = CalculandoRho();      //  Operador N
                Rho2 = CalculandoRho2();    //  Operador N*N
                
                myfile1<<x<<"\t"<<Psi0<<"\n";
                myfile2<<x<<"\t"<<Rho<<"\n";
                myfile3<<x<<"\t"<<Rho2<<"\n";
                myfile4<<x<<"\t"<<sqrt(Rho2-Rho*Rho)<<"\n";
                
                for(j=0;j<n+1;j++)  //  Evaluando que eigenvector sea real
                {
                   if(EigenVectorsImag[PositionEigenValue][j]!=0)
                   {
                       cout<<"\n Componente imaginaria encontrada.";
                   }
                    
                }
            }
            
            PsiAnterior = Psi0;
            k++;
        }
    }
    myfile1.close();
    myfile2.close();
    myfile3.close();
    myfile4.close();
    cout<<"\n\nFin del programa. Adios.\n\n";
    return 0; 
}
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
void DefinirOperadores()
{
    int i, j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            OperadorN[i][j] = 0;
            OperadorN2[i][j] = 0;
            OperadorB[i][j] = 0; 
            OperadorBDaga[i][j] = 0; 
            OperadorIdentidad[i][j] = 0;
            
            if(i==j)
            {
                OperadorN[i][j] = i; 
                OperadorN2[i][j] = i*i;
                OperadorIdentidad[i][j] = 1;
            }
            if(i==(j+1))    OperadorB[i][j] = pow(i,0.5);
            if(i==(j-1))    OperadorBDaga[i][j] = pow(i+1,0.5);
        }
    }
}
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
void Imprimir(double Matrix[n+1][n+1])
{
    int i, j;
    cout<<"\n-----------------------------------------------------------------";
    for(i=0;i<=n;i++)
    {
        cout<<"\n";
        for(j=0;j<=n;j++)
        {
            cout<<"\t"<<Matrix[i][j]; 
        }
    }
    cout<<"\n-----------------------------------------------------------------";
}
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
void CalculandoHEfectivo(double Psi, double x, double mu)
{
    int i, j;
    double y;
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            y = -x*Psi*OperadorB[i][j];
            y  = y  - x*Psi*OperadorBDaga[i][j];
            y  = y  + x*Psi*Psi*OperadorIdentidad[i][j];
            y  = y  + (OperadorN2[i][j] - OperadorN[i][j])/2;
            OperadorHEfectivo[i][j] = y  - x*mu*OperadorN[i][j];
        }
    }
}
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
void CalculandoEigen()
{
    int i, j;
    double x=0;
    
    mat A;          // Matrix en Armadillo
    cx_vec val;     // Vec complejos
    cx_mat vec;     // Matrix compleja
    
    A.set_size(n+1,n+1);
    
    for(i=0;i<=n;i++)   for(j=0;j<=n;j++)   A(i,j) = OperadorHEfectivo[i][j];
    
    
    eig_gen(val,vec,A);     //  Eigenvalores en Armadillo
    
    PositionEigenValue = 0;         //  Posicion Egenvalor minimo inicial
    EigenValueMin=real(val(0));     //  Valor Eigenvalor minimo inical
    
    for(i=0;i<=n;i++)
    {
        EigenValues[i] = real(val(i));
        
        for(j=0;j<=n;j++)
        {
            EigenVectorsReales[i][j] = real(vec(j,i));
            EigenVectorsImag[i][j] = imag(vec(j,i));
        }
        
        x = EigenValues[i];
        
        if(x<EigenValueMin)     //  Encontrando eigenvalor minimo
        {
            EigenValueMin = x;
            PositionEigenValue = i;
        }
    }
}
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
double CalculandoNuevoPsi()
{
    int i, j;
    double Psi = 0;
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            Psi=Psi+EigenVectorsReales[PositionEigenValue][i]*OperadorB[i][j]*EigenVectorsReales[PositionEigenValue][j];
        }
    }
    return Psi;
}
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
double CalculandoRho()
{
    int i, j;
    double Rho = 0;
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            Rho=Rho+EigenVectorsReales[PositionEigenValue][i]*OperadorN[i][j]*EigenVectorsReales[PositionEigenValue][j];
        }
    }
    return Rho;
}
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
double CalculandoRho2()
{
    int i, j;
    double Rho2 = 0;
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            Rho2=Rho2+EigenVectorsReales[PositionEigenValue][i]*OperadorN2[i][j]*EigenVectorsReales[PositionEigenValue][j];
        }
    }
    return Rho2;
}
