set terminal postscript eps size 3,3 enhanced color
set out 'Graph_Trayectoria.eps'

#set xtics (1,2,3,4)


set grid
set key  b font ",18"

set size square

#set xrange [-40:40]
#set yrange [-40:40]

set xlabel "Momento inicial, p_0" font ", 18"
set ylabel "Theta(t=0) - Theta(t=0) = Pi/2" font ",18"


plot 'RK4.txt' using 1:2 w l lt rgb "red" notitle
