set terminal postscript eps size 4,3 enhanced color
set out 'Grafica_Theta_Tiempo.eps'

set grid
set key  b font ",18"

set size square

#set xrange [-40:40]
#set yrange [-40:40]

set xlabel "t (u. a.)" font ", 18"
set ylabel "Angulo" font ",18"


plot 'RK4_DoubleOscillator.txt' using 1:2 w l lt rgb "red" title "Theta 1", 'RK4_DoubleOscillator.txt' using 1:3 w l lt rgb "blue" title "Theta 2"
