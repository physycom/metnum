#!/gnuplot
FILE="fort.2"  
 set terminal  png  enhanced
 set output 'Fig2.png'
# set terminal postscript eps enhanced colour solid rounded "Helvetica" 25
# set output 'fig.ps'
set title  "  Runge-Kutta  errore su H  " 
set xlabel " t " 
set ylabel " err " 
#      set xrange [-1:1]         
#      set yrange [-1:1] 
      set logscale y 
      set format y '10^{%L}'
       plot FILE    u  1:2  w  lines     lt  1   lc   rgb "blue"   lw 2   t    ' RK  '   