#!/gnuplot
FILE_IN='out.txt'
set terminal png enhanced
#set terminal pngcairo
set output "quadrature.png"

set xlabel 'N' 
set ylabel 'Error'

set logscale y
set yrange [1e-5:2]
set format y "10^{%L}"


plot FILE_IN using 1:(abs($2)) with points pointtype 7 linecolor rgb 'blue' title 'Rettangoli',\
     FILE_IN using 1:(abs($3)) with points pointtype 4 linecolor rgb 'red' title 'Trapezi'
