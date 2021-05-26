set terminal postscript eps size 4,3 enhanced color
set out 'Grafica_EspacioFase.eps'

#set xtics (1,2,3,4)

set grid
set key  b font ",18"

#set size square

#set xrange [-40:40]
#set yrange [-40:40]

set xlabel "Theta_2" font ", 18"
set ylabel "P_2" font ",18"


plot 'RK4_DoubleOscillator.txt' using 3:4 with points pointtype 7 ps 0.2 lt rgb "red" notitle
