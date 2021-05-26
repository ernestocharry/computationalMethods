#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <time.h>
#include <random>

#include <string>

// Para interpolar
#include <cstdio>
#include <cstdlib>
#include <vector>


using namespace std;

double xMin, xMax, yMin, yMax, tMin, tMax;
double deltaX, deltaY, deltaT;

const int xPuntos = 100;
const int yPuntos = 100;
const int tPuntos = 100;

const int NoParticulaes = 20;

double Posicion[NoParticulaes][NoParticulaes][NoParticulaes][NoParticulaes][tPuntos];   // x, y, vx, vy, t
double Caracteristicas[tPuntos][3]; // 3 para guardar E, K, Temperatura

int main()
{

    xMin = -10;
    xMax = +10;
    yMin = -10;
    yMax = +10;
    tMin = 0;
    tMax = 5;

    deltaX = (xMax-xMin)/(xPuntos-1);
    deltaY = (yMax-yMin)/(yPuntos-1);
    deltaT = (tMax-tMin)/(tPuntos-1);
    

}

