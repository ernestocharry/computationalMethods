set terminal postscript eps size 4,3 enhanced color
set out 'Solucion.eps'

set grid
set key  b font ",18"


set xlabel "Tiempo" font ", 18"
set ylabel "Theta o P" font ",18"


plot 'Solucion.txt' using 1:2 w l lt rgb "red" title "Theta", 'Solucion.txt' using 1:3 w l lt rgb "blue" title "P",
