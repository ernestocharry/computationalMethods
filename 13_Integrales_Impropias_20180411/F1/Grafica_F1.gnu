set terminal postscript eps size 4,5 enhanced color
set out '13_F1.eps'

#set xtics (1,2,3,4)

set key  b font ",18"
set grid
set key right top

set multiplot layout 3,1 rowsfirst

unset log y
#unset format y "10^{%T}"
set ylabel "f_1(x)" font ",18"
set xlabel "x" font ", 18"
set xrange[0:1]
set yrange[0:0.5]
plot 'F1.txt' u 1:2 w l lw 3 lc rgb "blue" notitle, 'Linea.txt' u 1:2 w l lw 3 lc rgb "black" notitle

# unset log y
set ylabel "Error relativo" font ",18"
set xlabel "N, 2^N puntos." font ", 18"
set xrange[0:20]



unset log y
#unset format y "10^{%T}"
set ylabel "Valor de la integral" font ",18"
set xlabel "N, numero de iteraciones" font ", 18"
set xrange[0:20]
set yrange[0.3:0.4]
plot 'F1_Integral_Error.txt' u 1:2  pt 7 ps 1 lc rgb 'blue' title 'Valor de Integral = 0.355066', 'F1_Integral_Error.txt' u 1:2 w l lw 3 lc rgb 'blue' notitle


unset log y
unset format y
set ylabel "Valor de la integral " font ",18"
#set yrange[1.160:1.162]

set log y
set format y "10^{%T}"
set ylabel "Error" font ",18"
set xlabel "N, numero de iteraciones" font ", 18"
set xrange[0:20]
set yrange[0.000000000000000001:0.4]
plot 'F1_Integral_Error.txt' u 1:3  pt 7 ps 1 lc rgb 'blue' notitle, 'F1_Integral_Error.txt' u 1:3 w l lw 3 lc rgb 'blue' notitle

unset multiplot
