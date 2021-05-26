set terminal postscript eps size 3,4 enhanced color
set out '8_NewtonRaphson2D_Ernesto_20180304.eps'
set logscale y
set format y "10^{%T}"
set xrange [1:5]
set yrange [0.000000000000000001:1]
set xtics (1,2,3,4,5)

set xlabel "No. de iteraciones" font ",18"
set ylabel "Valor absoluto de Max(g_1, g_2)" font ",18"


set key  b font ",12"
set grid

plot 'NewtonRaphson2D_x0_-2_y0_-3.txt' u 1:8 w l lw 3 lc rgb 'red' title '(x0, y0) = (-2, -3)', 'NewtonRaphson2D_x0_-2_y0_-3.txt' u 1:8 w p lc rgb 'black' pt 7 notitle, 'NewtonRaphson2D_x0_-2_y0_1.txt' u 1:8 w l lw 3 lc rgb 'blue' title '(x0, y0) = (-2, 1)', 'NewtonRaphson2D_x0_-2_y0_1.txt' u 1:8 w p lc rgb 'black' pt 7 notitle, 'NewtonRaphson2D_x0_-4_y0_3.txt' u 1:8 w l lw 3 lc rgb 'purple' title '(x0, y0) = (-4, 3)', 'NewtonRaphson2D_x0_-4_y0_3.txt' u 1:8 w p lc rgb 'black' pt 7 notitle, 'NewtonRaphson2D_x0_-5_y0_-6.txt' u 1:8 w l lw 3 lc rgb 'olive' title '(x0, y0) = (-5, -6)', 'NewtonRaphson2D_x0_-5_y0_-6.txt' u 1:8 w p lc rgb 'black' pt 7 notitle, 'NewtonRaphson2D_x0_-6_y0_7.txt' u 1:8 w l lw 3 lc rgb 'green' title '(x0, y0) = (-6, 7)', 'NewtonRaphson2D_x0_-6_y0_7.txt' u 1:8 w p lc rgb 'black' pt 7 notitle, 'line.txt' u 1:2 w l dt 7 lw 3 lt 2 lc rgb 'black' title 'Limite'
