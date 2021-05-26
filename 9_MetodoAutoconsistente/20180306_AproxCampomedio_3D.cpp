#include <iostream>
#include <time.h>
#include <fstream>
#include <math.h>
#include <armadillo>

using namespace std;
using namespace arma;

const int n = 10;      // System size
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
    int i,j,k,l;
    int InterationsMax;
    double Psi0, PsiAnterior;
    double x, aux, mu;
    double ErrorLimit, ErrorDiferencia;
    double norma, Rho, Rho2;
    
    ofstream myfile3D;
    myfile3D.open("AproxCampoMedio3D_x_auxiliar_Psi.txt");
    
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
    
    double xMin= pow(10,-3);
    double xMax =0.2;
    int xN = 400;
    double xDelta = (xMax-xMin)/xN;
    
    double auxMin= pow(10,-3);
    double auxMax = 5;
    int auxN = 400;
    double auxDelta = (auxMax-auxMin)/auxN;
    
    for(i=0; i<=xN; i++)
    {
        x =xDelta*i + xMin;
        
        for(j=0;j<=auxN;j++)
        {
            aux = auxDelta*j + auxMin;
            mu = aux/x;
            k=0;
            Psi0    =   0.1;
            PsiAnterior = Psi0 + 10;

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
//                    Rho = CalculandoRho();
//                    Rho2 = CalculandoRho2();
                    
                    myfile3D<<x<<"\t"<<aux <<"\t"<<Psi0<<"\n";
                    
                    norma = 0;
                    for(l=0;l<n+1;l++)
                    {
                        norma=norma+pow(EigenVectorsReales[PositionEigenValue][l],2);
                        if(EigenVectorsImag[PositionEigenValue][l]!=0)
                        {
                            cout<<"\n Componente Imaginaria encontrada";
                        }
                        
                    }
                    if(norma!=1)    // Numericamente la norma no es 1, es aprox. 1
                    {
                  //      cout<<"\n Vector No normalizado encontrado. ";
                    //    cout<<"Valor de su norma: "<<norma;
                    }
                }
                PsiAnterior = Psi0;
                k++;
            }
        }
        
        
        
    }
    myfile3D.close();
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
            y = y  + x*Psi*Psi*OperadorIdentidad[i][j];
            y  = y  + (OperadorN2[i][j] - OperadorN[i][j])/2;
            OperadorHEfectivo[i][j] = y - mu*x*OperadorN[i][j];
        }
    }
}
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
void CalculandoEigen()
{
    int i, j;
    double x;
    
    mat A;          // Matrix en Armadillo. Mirar spmat en Armadillo
    cx_vec val;     // Vec complejos
    cx_mat vec;     // Matrix compleja
    
    A.set_size(n+1,n+1);
    
    for(i=0;i<=n;i++)   for(j=0;j<=n;j++)   A(i,j) = OperadorHEfectivo[i][j];

    eig_gen(val,vec,A);

    x=0;
    PositionEigenValue = 0;
    EigenValueMin=real(val(0));
    
    for(i=0;i<=n;i++)
    {
        EigenValues[i] = real(val(i));

        for(j=0;j<=n;j++)
        {
            EigenVectorsReales[i][j] = real(vec(j,i));
            EigenVectorsImag[i][j] = imag(vec(j,i));
        }

        x = EigenValues[i];
        if(x<EigenValueMin)
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
