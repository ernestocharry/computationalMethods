set terminal postscript eps size 3,3 enhanced color
set out 'Parte_A.eps'

set key  b font ",18"
set grid
set key right top

set ylabel "Y-axis" font ",18"
set xlabel "X-axis" font ", 18"

plot 'Euler.txt' u 1:2 w l lw 3 lc rgb "blue" title 'Euler', 'MidPoint.txt' u 1:2 w l lw 3 lc rgb "red" title 'Punto medio', 'Rk4.txt' u 1:2 w l lw 3 lc rgb "orange" title 'Runge-Kutta 4'
