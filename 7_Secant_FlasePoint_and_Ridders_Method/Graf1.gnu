set terminal postscript eps size 5.3,3 enhanced color
set out '7_Comparison_Ernesto_20180301.eps'
set logscale y
set format y "10^{%T}"
set xrange [1.1:45]

set xlabel "No. de iteraciones"
set ylabel "Valor absoluto (f_i - f_{i-1})"


plot 'BisectionMethod_Error_vs_Interations.txt' u 1:2 w l lw 3 lc rgb 'red' title 'BisectionMethod', 'NewtonRaphsonMethod_Error_vs_Interations.txt' u 1:2  w l lw 3 lc rgb 'blue' title 'NewtonRaphsonMethod', 'BisectionMethod_Error_vs_Interations.txt' u 1:2 w p lc rgb 'black' pt 7 notitle, 'NewtonRaphsonMethod_Error_vs_Interations.txt' w p lc rgb 'black' pt 9 notitle, 'FalsePointMethod_Error_vs_Interations.txt' u 1:2 w l lw 3 lc rgb 'purple' title 'FlasePointMethod','FalsePointMethod_Error_vs_Interations.txt' u 1:2 w p lc rgb 'black' pt 7 notitle, 'RiddersMethod_Error_vs_Interations.txt' u 1:2 w l lw 3 lc rgb 'olive' title 'RiddersMethod','RiddersMethod_Error_vs_Interations.txt' u 1:2 w p lc rgb 'black' pt 7 notitle, 'SecantMethod_Error_vs_Interations.txt' u 1:2 w l lw 3 lc rgb 'green' title 'SecantMethod','SecantMethod_Error_vs_Interations.txt' u 1:2 w p lc rgb 'black' pt 7 notitle, 'line.txt' u 1:2 w l lw 1 lt 2 lc rgb 'black' title 'Limite'
