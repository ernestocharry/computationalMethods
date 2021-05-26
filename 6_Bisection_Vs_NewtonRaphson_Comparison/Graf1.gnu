set terminal postscript eps size 5.3,3 enhanced color
set out 'Comparison.eps'
set logscale y
set format y "10^{%T}"
set xrange [1.1:40]

set xlabel "No. de iteraciones"
set ylabel "Error: abs|f_i - f_{i-1}|"


plot 'BisectionMethod_Error_vs_Interations.txt' u 1:2 w l lw 3 lc rgb 'red' title 'BisectionMethod', 'NewtonRaphsonMethod_Error_vs_Interations.txt' u 1:2  w l lw 3 lc rgb 'blue' title 'NewtonRaphsonMethod', 'BisectionMethod_Error_vs_Interations.txt' u 1:2 w p lc rgb 'black' pt 7 notitle, 'NewtonRaphsonMethod_Error_vs_Interations.txt' w p lc rgb 'black' pt 9 notitle
