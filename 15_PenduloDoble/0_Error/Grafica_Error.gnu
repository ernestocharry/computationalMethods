set terminal postscript eps size 4.5,4 enhanced color
set out 'Graph_Harmonic_Oscillator.eps'

set key  b font ",18"
set grid
set key right top
set multiplot layout 2,2 rowsfirst

set xlabel "Numero de puntos, N" font ", 18"

set log y
set log x
set format y "10^{%T}"
set format x "10^{%T}"

set ylabel "Error relativo Theta_1" font ",18"
plot 'Error.txt' u 1:13 w l lw 3 lc rgb "red" notitle

set ylabel "Error relativo Theta_2" font ",18"
plot 'Error.txt' u 1:14  w l lw 3 lc rgb "black" notitle

set ylabel "Error relativo P_1" font ",18"
plot 'Error.txt' u 1:15 w l lw 3 lc rgb "blue" notitle

set ylabel "Error relativo P_2" font ",18"
plot 'Error.txt' u 1:16  w l lw 3 lc rgb "orange" notitle

unset multiplot
