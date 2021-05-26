set terminal postscript eps size 5.3,3 enhanced color
set out 'Graph_Harmonic_Oscillator.eps'

set key  b font ",18"
set grid
set key right top

set ylabel "Amplitud" font ",18"
set xlabel "Tiempo (unidades arbitrarias)" font ", 18"

plot 'RK4.txt' u 1:2 w l lw 3 lc rgb "red" title "Theta", 'RK4.txt' u 1:3 w l lt 0  lc rgb "blue" lw 3 title "Aprox.",'RK4.txt' u 1:4 w l lw 3 lc rgb "black" title "Momento, P."
