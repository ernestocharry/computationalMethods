set terminal postscript eps size 4,5 enhanced color
set out '13_F4.eps'

#set xtics (1,2,3,4)

set key  b font ",18"
set grid
set key right top

set multiplot layout 3,1 rowsfirst

set log y
#unset format y "10^{%T}"
set ylabel "f_4(x)" font ",18"
set xlabel "x" font ", 18"
set xrange[0:3]
set yrange[0.0001:10]
plot 'F4.txt' u 1:2 w l lw 3 lc rgb "violet" notitle

unset log y
#unset format y "10^{%T}"
set ylabel "Valor de la integral" font ",18"
set xlabel "N, numero de iteraciones" font ", 18"
set xrange[0:40]
set yrange[1.2:1.3]
plot 'F4_Integral_Error.txt' u 1:2  pt 7 ps 1 lc rgb 'violet' title 'Valor de Integral = 1.246631', 'F4_Integral_Error.txt' u 1:2 w l lw 3 lc rgb 'violet' notitle

set log y
set format y "10^{%T}"
set ylabel "Error" font ",18"
set xlabel "N, numero de iteraciones" font ", 18"
set xrange[0:40]
set yrange[0.0000000001:10]
plot 'F4_Integral_Error.txt' u 1:3  pt 7 ps 1 lc rgb 'violet' notitle, 'F4_Integral_Error.txt' u 1:3 w l lw 3 lc rgb 'violet' notitle

unset multiplot
