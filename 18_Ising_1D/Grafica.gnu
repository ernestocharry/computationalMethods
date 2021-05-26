set terminal postscript eps size 4,5 enhanced color
set out 'Grafica.eps'

set encoding utf8

set key  b font ",18"
set grid
set key right top
set multiplot layout 2,1 rowsfirst


set ylabel "Magnetización" font ",18"
set xlabel "Beta" font ", 18"


plot 'Solucion.txt' u 1:2 w l lw 3 lc rgb "violet" notitle "x = theta",

set ylabel "Energia" font ",18"
set xlabel "Beta" font ", 18"


plot 'Solucion.txt' u 1:3 w l lw 3 lc rgb "blue" notitle "x = theta",


unset multiplot
