set terminal postscript eps size 4,3 enhanced color
set out 'Grafica_P0.eps'

set grid
set key  b font ",18"

#set xrange [-40:40]
#set yrange [-40:40]

set xlabel "Semilla para momento inicial" font ", 18"
set ylabel "Momento inicial" font ",18"


plot 'P0_Pf.txt' using 1:2 w p pt 5 lt rgb "red" notitle
