set terminal postscript eps size 5.5,4.3 enhanced color
set out 'Grafica_P0.eps'



set key  b font ",18"
set grid
set key right b


set multiplot layout 2,2 rowsfirst

set xlabel "Tiempo" font ", 18"
set ylabel "Theta o P" font ",18"

plot 'Solucion_0.859399.txt' using 1:2 w l lt rgb "red" title "Theta", 'Solucion_0.859399.txt' using 1:3 w l lt rgb "blue" title "P", 'Solucion_0.859399.txt' using 1:4 w l lw 2 lt rgb "black" title "Energy = 1.34"

plot 'Solucion_-1.23592.txt' using 1:2 w l lt rgb "red" title "Theta", 'Solucion_-1.23592.txt' using 1:3 w l lt rgb "blue" title "P", 'Solucion_-1.23592.txt' using 1:4 w l lw 2 lt rgb "black" title "Energy = 1.76"

plot 'Solucion_1.23592.txt' using 1:2 w l lt rgb "red" title "Theta", 'Solucion_1.23592.txt' using 1:3 w l lt rgb "blue" title "P", 'Solucion_1.23592.txt' using 1:4 w l lw 2 lt rgb "black" title "Energy = 1.76"

plot 'Solucion_-1.41493.txt' using 1:2 w l lt rgb "red" title "Theta", 'Solucion_-1.41493.txt' using 1:3 w l lt rgb "blue" title "P", 'Solucion_-1.41493.txt' using 1:4 w l lw 2 lt rgb "black" title "Energy = 2.00"
unset multiplot
