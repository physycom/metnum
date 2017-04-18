#!/gnuplot
FILE_IN_1='dati_leapfrog.txt'
FILE_IN_2='dati_rk2.txt'
FILE_IN_3='dati_rk4.txt'
FILE_IN_4='dati_eulero.txt'
FILE_OUT='confronto.png'
set terminal png enhanced
set output FILE_OUT
set xlabel 'x' 
set ylabel 'px'
set pointsize 0.2
plot FILE_IN_1 u 1:2 w points pt 7 lc rgb 'blue' lw 3 t 'LF',\
     FILE_IN_2 u 1:2 w points pt 7 lc rgb 'red' lw 3 t 'RK2',\
     FILE_IN_3 u 1:2 w points pt 7 lc rgb 'green' lw 3 t 'RK4',\
     FILE_IN_4 u 1:2 w points pt 7 lc rgb 'orange' lw 3 t 'EU'