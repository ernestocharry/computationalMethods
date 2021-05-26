set terminal postscript eps size 4,4 enhanced color
set out '9_Grafica_AproxCampoMedio3D_x_aux_Psi.eps'

#set xtics (1,2,3,4)

set key  b font ",18"
set grid

set xlabel "x" font ",18"
set ylabel "aux" font ",18"

set key on
set view map
splot 'AproxCampoMedio3D_x_auxiliar_Psi.txt' using 1:2:3 with points pointtype 5 pointsize 1 palette linewidth 30
