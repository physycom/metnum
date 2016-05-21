#!/gnuplot

FILE_IN = 'out.txt'
set terminal png enhanced
#pngcairo
#gnuplotting.org

set output "quadrature.png"

set xlabel 'N'
set ylabel 'Error'
set logscale y
#set yrange [1e-5:2]
#set format y "10^{%L}"
plot FILE_IN using 1:(abs($2)) with points pointtype 7 linecolor rgb 'blue' title 'Rettangoli' , '' using 1:(abs($3)) with points pointtype 7 linecolor rgb 'red' title 'Trapezi', '' using 1:(abs($4)) with points pointtype 7 linecolor rgb 'green' title 'Simpson'
