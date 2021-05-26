set terminal postscript eps size 4,4 enhanced color
set out 'Condiciones_Iniciales.eps'


set key  b font ",18"
set grid

#set log x
#set log y
#set format x "10^{%T}"
#set format y "10^{%T}"

set title "P10 = P20 = 0. Omega = E5. m=g=1"
set xlabel "T10 (rad)" font ",18"
set ylabel "T20 (rad)" font ",18"

set xrange [-3.142:3.142]
set yrange [-3.142:3.142]

set size ratio 1
set key on

set pm3d
set pm3d map
set logscale cb

set palette cubehelix

splot 'CriticalTimeTheta2.txt' using 7:8:1 with points pointtype 5 pointsize 0.7 palette linewidth 30 notitle
