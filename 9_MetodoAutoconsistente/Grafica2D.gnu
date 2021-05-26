set terminal postscript eps size 4.5,6 enhanced color
set out '9_Grafica_AproxCampoMedio2D_x_Psi.eps'

#set xtics (1,2,3,4)

set key  b font ",18"
set grid



set multiplot layout 3,1 rowsfirst


unset xlabel;
set ylabel "Psi" font ",18"
plot 'AproxCampoMedio2D_x_Psi.txt' u 1:2 w l lw 3 lc rgb 'blue' notitle, 'AproxCampoMedio2D_x_Psi.txt' u 1:2 w p lc rgb 'blue' pt 7 notitle

unset xlabel;
set ylabel "Rho" font ",18"
plot 'AproxCampoMedio2D_x_Rho.txt' u 1:2 w l lw 3 lc rgb 'red' notitle, 'AproxCampoMedio2D_x_Rho.txt' u 1:2 w p lc rgb 'red' pt 7 notitle

set xlabel "x" font ",18"
set ylabel "sqrt( <Rho^2> - <Rho>^2 )" font ",18"
plot 'AproxCampoMedio2D_x_Diferencia_Rho2_RhoRho.txt' u 1:2 w l lw 3 lc rgb 'purple' notitle, 'AproxCampoMedio2D_x_Diferencia_Rho2_RhoRho.txt' u 1:2 w p lc rgb 'purple' pt 7 notitle

unset multiplot
