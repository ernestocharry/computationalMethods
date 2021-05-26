#!/usr/bin/python
# -*- coding_ utf8 -*-

# Autor: Feelix Ernesto Charry Pastrana
# Correo: feecharrypa@unal.edu.co
# 2019 07 23
#
# This code analyzes determine the value of the gravity (g)
# using images extracted from the video
#
# PeenduloSimple_DeterminacioonDeLaAceleracioonDeLa Gravedad.flv
#
# A set of images corresponding to a fixed length of
# the simple pendulum. The length and the corresponding images
# are in the vector L and Puntos, respectively.

from pylab import *
import numpy as np
import scipy
import scipy.ndimage as nd
import matplotlib.pyplot as plt
import math
from scipy.fftpack import fft, fftfreq
from collections import Counter
from numpy import polyval, polyfit

OmegCuadrados=[]

# These lenghts appear on the video. Uncertainty = +- 1 cm
L = [46.8, 59, 66, 78.5, 83]
InversoLongitudes = [100./46.8, 100./59, 100./66, 100./78.5, 100./83]

# Number in the image data
Puntos = [[236,1256],[1516,2761],[3016,4381],[4711,6151],[6401,7776]]


def Pendulo(NoImagMin,NoImagMax):

    tempo = 5
    # "tempo" is 5 because is the number of photographs per seconds
    NoImagenes = (NoImagMax-NoImagMin)/tempo;
    Tutto=np.zeros(NoImagenes+1)

    for k in range(NoImagMin,NoImagMax + 1,tempo):
        if k<1000:
            Bola1=imread("./Imagenes_from_Video/scene00"+str(k)+".png")
        else:
            Bola1=imread("./Imagenes_from_Video/scene0"+str(k)+".png")
        
        # Applying some filters to prepare the image for the
        # Calculus of "Center of Mass"
        Ce = np.array((0.9, 0.5, 0.45))
        S= Bola1-Ce
        D = np.sqrt((S**2).sum(axis=2))
        Gris = Bola1[:,:,0].astype("float")
        GrisBin= np.where(D<0.2,1,0)
        Filtro = nd.median_filter(GrisBin, (7,7))
        FiltroNumber,n = nd.label(Filtro)
        # Center of mass
        Elementos  = np.zeros(n+1)

        for i in range(0,480):
            counts = np.bincount( list(map(float, FiltroNumber[i])))
            longitud = len(counts)
            for j in range(1,longitud):
                a = counts[j]
                Elementos[j] = a + Elementos[j]
        max = np.max(Elementos)
        for l in range(1,n+1):
            if Elementos[l]==max:
                b = l
        # Measure the position of Center of Mass of the ball
        MassCenter = nd.measurements.center_of_mass(Filtro,FiltroNumber,b)
        # Adding the position of Center of Mass in Tutto
        Tutto[(k-NoImagMin)/tempo]=MassCenter[1]
    
    # Finding the frecuency using Fourier Transform
    FFT = np.fft.fft(Tutto)
    L0 = len(FFT)
    b=ceil(L0*0.5)

    FFT[0]=0
    FFT[b:L0] = 0

    FFT = abs(FFT)
    MaxFFT = np.max(FFT)

    Lol2=np.argmax(FFT)
    # Converting "image" frecuency to "real" frecuency (seconds -1)
    OmegaCuad = float((Lol2*tempo*tempo*10/(NoImagMax-NoImagMin))**2)
    return OmegaCuad

# Here is where the program starts
print '\n -------------------------------'
print '\n Program: find the gravity value from images extract form a YouTube video \n'
print '\n Autor: F. E. Charry-Pastrana, feecharrypa@unal.edu.co '
print '\n -------------------------------'

for i in range(0,len(InversoLongitudes),1):
    print '\nEl programa se encuentra corriendo sobre las '
    print 'imagenes correspondientes a la longitud de ',
    print L[i], 'cm'
    NoImagMin=Puntos[i][0]
    NoImagMax=Puntos[i][1]
    # Calling the function
    Pendulo(NoImagMin,NoImagMax)
    # Keep the results in OmegCuadrados to fit it then
    OmegCuadrados.append(Pendulo(NoImagMin,NoImagMax))


coeficientes = polyfit(InversoLongitudes,OmegCuadrados,1)
g= np.pi*np.pi*4*coeficientes[0]
gporcentual = abs((g-980)*100/980);

print '\n \n El valor de la gravedad encontrado es g =', g, ' (cm/s^2). \n'
print 'El error porcentual de este valor es ', gporcentual
