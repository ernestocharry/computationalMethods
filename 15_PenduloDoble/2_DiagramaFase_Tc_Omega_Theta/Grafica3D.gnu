set terminal postscript eps size 4,4 enhanced color
set out 'Omega_Theta_Tc_1.eps'

#set xtics (1,2,3,4)

set key  b font ",18"
set grid

set log x
#set log y
set log z
set format x "10^{%T}"
set format z "10^{%T}"

#set format y "10^{%T}"


set xlabel "Omega2 at fixed g = 1" font ",18"
set ylabel "T1_0 = T2_0 (rad)" font ",18"

set yrange[0:3.142]

set key on

set pm3d
set pm3d map
set logscale cb
set palette cubehelix

splot 'CriticalTimeTheta2.txt' using 4:7:1 with points pointtype 5 pointsize 0.7 palette linewidth 30 notitle
