set terminal postscript eps size 4,5 enhanced color
set out '12_Grafica_Integral_J0.eps'

#set xtics (1,2,3,4)

set key  b font ",18"
set grid
set key right top



set multiplot layout 3,1 rowsfirst


set ylabel "J_0 (x)" font ",18"
set xlabel "x, intervalo de integracion" font ", 18"


plot 'Funcion_J0.txt' u 1:2 w l lw 3 lc rgb "violet" notitle, 'Linea.txt' u 1:2 w l lw 3 lc rgb "black" notitle




set log y
set ylabel "Error relativo" font ",18"
set xlabel "N, 2^N puntos." font ", 18"

set format y "10^{%T}"

plot 'N_Integral_ErrRelativo.txt' u 1:3  pt 7 ps 1 lc rgb 'blue' title 'Trapezio', 'N_Integral_ErrRelativo.txt' u 1:3 w l lw 3 lc rgb 'blue' notitle,  'N_Integral_ErrRelativo.txt' u 1:5  pt 7 ps 1 lc rgb 'red' title 'Simpson 3-4', 'N_Integral_ErrRelativo.txt' u 1:5 w l lw 3 lc rgb 'red' notitle, 'N_Integral_ErrRelativo.txt' u 1:7  pt 7 ps 1 lc rgb 'black' title 'Simpson 3-8', 'N_Integral_ErrRelativo.txt' u 1:7 w l lw 3 lc rgb 'black' notitle

unset log y
unset format y
set ylabel "Valor de la integral Bessel J_0" font ",18"
set yrange[1.267:1.27]

plot 'N_Integral_ErrRelativo.txt' u 1:2  pt 7 ps 1 lc rgb 'blue' title 'Trapezio', 'N_Integral_ErrRelativo.txt' u 1:2 w l lw 3 lc rgb 'blue' notitle,  'N_Integral_ErrRelativo.txt' u 1:4  pt 7 ps 1 lc rgb 'red' title 'Simpson 3-4', 'N_Integral_ErrRelativo.txt' u 1:4 w l lw 3 lc rgb 'red' notitle, 'N_Integral_ErrRelativo.txt' u 1:6  pt 7 ps 1 lc rgb 'black' title 'Simpson 3-8', 'N_Integral_ErrRelativo.txt' u 1:6 w l lw 3 lc rgb 'black' notitle

unset multiplot
