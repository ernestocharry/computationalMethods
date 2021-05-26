set terminal postscript eps size 4,5 enhanced color
set out 'Verlet.eps'

set encoding utf8

set key  b font ",18"
set grid
set key right top

set multiplot layout 2,1 rowsfirst

set ylabel "Posición" font ",18"
set xlabel "tiempo (u. a.)" font ", 18"
plot 'Solucion.txt' using 1:4 w l lw 3 lc rgb "#e31a1c" notitle

set ylabel "Magnitud Velocidad" font ",18"
set xlabel "tiempo (u. a.)" font ", 18"
plot 'Solucion.txt' using 1:7 w l lw 3 lc rgb "#238b45" notitle

unset multiplot
