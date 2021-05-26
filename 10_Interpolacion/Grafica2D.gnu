set terminal postscript eps size 4,5 enhanced color
set out '9_Grafica_AproxCampoMedio2D_x_Psi.eps'

#set xtics (1,2,3,4)

set key  b font ",18"
set grid
set key right top

unset log y

set multiplot layout 2,1 rowsfirst

set ylabel "log(y)" font ",18"
set xlabel "x-axis" font ", 18"
#plot 'x_y_fit.txt' u 1:3 w l lw 3 lc rgb 'blue' notitle, 'x_y_aleatorio_initial_data.txt' u 1:3 w p lc rgb 'blue' pt 7 notitle

#plot 'x_y_fit.txt' using 1:2:3 with yerrorbars, 'x_y_aleatorio_initial_data.txt' u 1:2 w p lc rgb 'blue' pt 7 notitle

set style fill transparent solid 0.2 noborder

plot 'x_logY_logY-Error_logY+Error.txt' using 1:3:4 with filledcurves title '68% confidence', 'x_y_aleatorio_initial_data.txt' u 1:3  pt 7 ps 1 lw 3 title 'Experimental data', 'x_y_fit.txt' using 1:4 w l lw 3 lc rgb 'blue' title 'fit'


set ylabel "y" font ",18"

set label "a = 1.5060 +- 0.1628" at 1.2,4.3 font ",18"
set label "b = -2.0052 +- 0.1459" at 1.2,3.8 font ",18"

plot 'x_y_y-error_y+error.txt' using 1:3:4 with filledcurves title '68% confidence', 'x_y_aleatorio_initial_data.txt' u 1:2  pt 7 ps 1 lw 3 title 'Experimental data', 'x_y_y-error_y+error.txt' using 1:2 w l lw 3 lc rgb 'blue' title 'y = exp(a+b*x)'

unset multiplot
