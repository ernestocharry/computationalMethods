set terminal postscript eps size 3,3 enhanced color
set out 'Graph_Trayectoria.eps'

#set xtics (1,2,3,4)


set grid
set key  b font ",18"

set size square

#set xrange [-40:40]
#set yrange [-40:40]

set xlabel "X (mm)" font ", 18"
set ylabel "Y (mm)" font ",18"


plot 'RK4_DoubleOscillator.txt' using 6:7 w l lt rgb "red" notitle,  'RK4_DoubleOscillator.txt' using 8:9 w l lt rgb "blue" notitle,
