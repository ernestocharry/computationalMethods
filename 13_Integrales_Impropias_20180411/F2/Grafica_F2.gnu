set terminal postscript eps size 4,5 enhanced color
set out '13_F2.eps'

#set xtics (1,2,3,4)

set key  b font ",18"
set grid
set key right top

set multiplot layout 3,1 rowsfirst

set log y
#unset format y "10^{%T}"
set ylabel "f_2(x)" font ",18"
set xlabel "x" font ", 18"
set xrange[0:10]
set yrange[0.01:10]
plot 'F2.txt' u 1:2 w l lw 3 lc rgb "red" notitle, 'Linea.txt' u 1:2 w l lw 3 lc rgb "black" notitle

unset log y
#unset format y "10^{%T}"
set ylabel "Valor de la integral" font ",18"
set xlabel "N, numero de iteraciones" font ", 18"
set xrange[0:35]
set yrange[3.1:3.35]
plot 'F2_Integral_Error.txt' u 1:2  pt 7 ps 1 lc rgb 'red' title 'Valor de Integral = Pi', 'F2_Integral_Error.txt' u 1:2 w l lw 3 lc rgb 'red' notitle

set log y
set format y "10^{%T}"
set ylabel "Error" font ",18"
set xlabel "N, numero de iteraciones" font ", 18"
set xrange[0:35]
set yrange[0.00000000000000001:10]
plot 'F2_Integral_Error.txt' u 1:3  pt 7 ps 1 lc rgb 'red' notitle, 'F2_Integral_Error.txt' u 1:3 w l lw 3 lc rgb 'red' notitle

unset multiplot
