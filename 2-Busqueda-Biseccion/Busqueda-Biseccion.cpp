//  Universidad Nacional Autonoma de Colombia
//  Posgrado en Ciencias Fisicas
//  Introduccion a la Fisica Computacional
//  Profesor: Santiago Caballero
//  Autor: F. E. Charry-Pastrana
//  11.02.2017

//  El presente programa lee una lista de numeros
//  desde el archivo lista.txt. El archivo no tiene enter
//  despues del ultimo numero.

//  Primero se lee los datos y se guardan los numeros en el vector
//  Datos. Se lee maximo 100 numeros.

//  Posteriormente los datos en el vector se ordenan de
//  menor a mayor. El numero deseado se busca utilizando el metodo
//  de la biseccion, que es dividir el intervalor (posiciones en el
//  vector) a la mitad y comprarar, si el dato deseado es mayor
//  o menor respecto al velor del vector que se encuentra en la mitad
//  y seguir dividiendo el intervalo. 

#include <iostream>
#include <math.h>
#include <fstream>


using namespace std;

int main()
{
    int i, j, k, n;
    float DatoDeArchivo;    //Vamos a leer UNICAMENTE numeros
    float Datos[100];       //Vamos a guardar los Numeros en vector
    ifstream myFile;
    
    float Dato1, Dato2;
    
    myFile.open ("lista.txt");
    //Cuidado con el ultimo enter del archivo

    n=0;
    
    cout<<"\nLeyendo y guardando datos en vector: \n\n";
    if (myFile.is_open()) {
        while (!myFile.eof()) {
            myFile >> Datos[n];
            cout<<n<<"; "<<Datos[n]<<"\n";
            n++;
        }
    }
    myFile.close();
    
    cout << "\nNumero total de datos:" << n << "\n";
    
    //Ordenando datos en el vector
    for(i=0; i<(n-1); i++)
    {
        for(j=i+1; j<n; j++)
        {
            Dato1 = Datos[i];
            Dato2 = Datos[j];
            if(Dato2<Dato1)
            {
                Datos[j] = Dato1;
                Datos[i] = Dato2;
            }
        }
    }
    // Escribiendo los datos en terminal
    cout<<"\n\nPosicion\tDato\n\n";
    for(i=0; i<n; i++)
    {
        cout<<"\n"<<i<<"\t"<< Datos[i];
    }
    
    cout<<"\n\n";

    
    //Buscar Numero NumDeseado
    float NumDeseado = 34;
    cout<<"\nNumero deseado y buscado: "<<NumDeseado<<"\n";
    
    int n0 = 0;
    int n1 = ceil(n-1);
    int nMedio = ceil((n1-n0)/2);

    int a, b,c;

    float NumMedio = Datos[nMedio];
    float distancia = NumDeseado - NumMedio;
    
//    cout<<"\n\nANTES\n";
//    cout<<"\nn0: "<<n0;
//    cout<<"\nn1: "<<n1;
//    cout<<"\nnMedio: "<<nMedio;
//    cout<<"\nNumMedio: "<<NumMedio;
//    cout<<"\nDistancia: "<<distancia;
//    cout<<"\n\n";
    
    i = 0;
    
    // Valor absoluto raiz(numero**2)
    while( (sqrt(distancia*distancia) > 0.01) )
    {
        a = n0;
        b = n1;
        c = NumMedio;
        
        if(NumDeseado>NumMedio)
        {
            n0 = nMedio;
            nMedio = ceil((n0+(n1-n0)/2));
            NumMedio = Datos[nMedio];
            distancia = NumDeseado - NumMedio;
//            cout<<"\nDentro if > 0\n";
//            cout<<"\nn0: "<<n0;
//            cout<<"\nn1: "<<n1;
//            cout<<"\nnMedio: "<<nMedio;
//            cout<<"\nNumMedio: "<<NumMedio;
//            cout<<"\nDistancia: "<<distancia;
//            cout<<"\n\n";
        }
        
        if(NumDeseado<NumMedio)
        {
            n1 = nMedio;
            nMedio = ceil((n0+(n1-n0)/2));
            NumMedio = Datos[nMedio];
            distancia = NumDeseado - NumMedio;
//            cout<<"\nDentro if < 0\n";
//            cout<<"\nn0: "<<n0;
//            cout<<"\nn1: "<<n1;
//            cout<<"\nnMedio: "<<nMedio;
//            cout<<"\nNumMedio: "<<NumMedio;
//            cout<<"\nDistancia: "<<distancia;
//            cout<<"\n\n";
        }
        
        if(distancia==0)
        {
            cout<<"\n\nNumero encontrado en la posicion "<<nMedio<<"\n\n";
        }
        
        i=i+1;
        
        if(i==n)
        {
            distancia = 0;
            cout<<"\n\nEl numero deseado no esta en la lista\n\n";
            cout<<"\nLos numeros mas cercanos se encuentran en ";
            cout<<"las posiciones "<<nMedio<<" y "<<nMedio+1;
            cout<<"\nCorresponden a los numeros: "<<Datos[nMedio];
            cout<<" y "<<Datos[nMedio+1]<<"\n\n";
        }
    }
    
    
    return 0;
}
