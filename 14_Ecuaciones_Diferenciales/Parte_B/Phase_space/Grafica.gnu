set terminal postscript eps size 3,3 enhanced color
set out 'Phase_Space.eps'

set xtics (-2,-1,0,1,2)
set ytics (-2,-1,0,1,2)

set key  b font ",18"
set grid
set key right top

set ylabel "P" font ",18"
set xlabel "Theta" font ", 18"

set xrange [-2.5:2.5]
set size ratio -1

plot 'RK4.txt' u 2:4 w l lw 3 lc rgb "blue" notitle, 'Pi2P0.txt' u 2:4 w l lw 3 lc rgb "blue" notitle, 'Pi16P0.txt' u 2:4 w l lw 3 lc rgb "blue" notitle, 'Pi4P1.txt' u 2:4 w l lw 3 lc rgb "blue" notitle, 'Pi2P1.txt' u 2:4 w l lw 3 lc rgb "blue" notitle, 'm3P15.txt' u 2:4 w l lw 3 lc rgb "blue" notitle, '3Pm15.txt' u 2:4 w l lw 3 lc rgb "blue" notitle
