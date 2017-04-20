#!/gnuplot
FILE="fort.2"  
 set terminal  png  enhanced
 set output 'Fig2.png'
# set terminal postscript eps enhanced colour solid rounded "Helvetica" 25
# set output 'fig.ps'
set title  " Integratori per H(q,p)  errore  " 
set xlabel " t " 
set ylabel " err " 
#       set xrange [0:1]         
#       set yrange [-1:1] 
      set logscale y 
      set format y '10^{%L}'
       plot FILE    u  2:(abs($3))  w  lines      lt  1   lc   rgb "cyan"    lw  2   t     ' sym 1  ' ,\
            FILE    u  2:(abs($4))  w  lines      lt  1   lc   rgb "blue"    lw  2   t     ' sym 2  ' ,\
	    FILE    u  2:(abs($5))  w  lines      lt  1   lc   rgb "green"   lw  2   t     ' sym 4  ' ,\
            FILE    u  2:(abs($6))  w  lines      lt  1   lc   rgb "purple"  lw  2   t     ' sym 6  ' ,\
	    FILE    u  2:(abs($7))  w  lines      lt  1   lc   rgb "red"     lw  2   t     ' sym 8  ' 