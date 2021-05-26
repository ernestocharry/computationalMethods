set terminal postscript eps size 4,3 enhanced color
set out 'Grafica_TCritico_L.eps'

#set xtics (1,2,3,4)

set grid
set key t font ",15"

#set size square

set log x
set log y
#set xrange [-40:40]
#set yrange [-40:40]

set xlabel "Omega2 at fixed g = 1" font ", 18"
set ylabel "Critical time at abs(Theta 2) > Pi" font ",18"
set format x "10^{%T}"
set format y "10^{%T}"


plot 'CriticalTime1.txt' using 4:1 with points pointtype 7 ps 0.5 lt rgb "red" title 'T1_0 = T2_0 = Pi/2, P1_0 = P2_0 = 0. Primera inversion', 'CriticalTime2.txt' using 4:1 with points pointtype 7 ps 0.5 lt rgb "blue" title 'Segunda inversion'
