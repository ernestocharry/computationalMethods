set terminal postscript eps size 4.5,4 enhanced color
set out 'Graph_Harmonic_Oscillator.eps'

set key  b font ",18"
set grid
set key right top
set multiplot layout 2,1 rowsfirst

set xlabel "Numero de puntos, N" font ", 18"

set log y
set log x
set format y "10^{%T}"
set format x "10^{%T}"

set ylabel "Diff. en Theta con N anterior" font ",18"
plot 'N_Theta0_PTheta0_Tfinal_ThetaFinal_PThetaFinal_ErrorTheta_ErrorP.txt' u 1:7 w l lw 3 lc rgb "red" notitle

set ylabel "Diff. en P con N anterior" font ",18"
plot 'N_Theta0_PTheta0_Tfinal_ThetaFinal_PThetaFinal_ErrorTheta_ErrorP.txt' u 1:8  w l lw 3 lc rgb "black" notitle

unset multiplot
