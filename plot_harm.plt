#!/gnuplot
FILE_IN='out.txt'

FILE_OUT='confronto.png'

set terminal png enhanced
set output FILE_OUT
set xlabel 'x' 
set ylabel 'px'
set pointsize 0.2

set logscale y

plot FILE_IN u 1:2 w points pt 7 lc rgb 'blue' lw 3 t 'EU',\
     FILE_IN u 1:3 w points pt 7 lc rgb 'red' lw 3 t 'LF'
     #FILE_IN_3 u 1:2 w points pt 7 lc rgb 'green' lw 3 t 'RK4',\
     #FILE_IN_4 u 1:2 w points pt 7 lc rgb 'orange' lw 3 t 'EU'
