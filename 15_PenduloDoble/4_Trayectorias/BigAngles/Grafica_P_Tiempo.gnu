set terminal postscript eps size 4,3 enhanced color
set out 'Grafica_P_Tiempo.eps'

#set xtics (1,2,3,4)


set grid
set key  b font ",18"

set size square

#set xrange [-40:40]
#set yrange [-40:40]

set xlabel "t (u. a.)" font ", 18"
set ylabel "Momento P" font ",18"


plot 'RK4_DoubleOscillator.txt' using 1:4 w l lt rgb "red" title "P_1", 'RK4_DoubleOscillator.txt' using 1:5 w l lt rgb "blue" title "P_2"
