#!/gnuplot
FILE="fort.1"  
 set terminal  png  enhanced
 set output 'Fig.png'
# set terminal postscript eps enhanced colour solid rounded "Helvetica" 25
# set output 'fig.ps'
set title  " Integratori per H(q,p)  " 
set xlabel " x " 
set ylabel " p "



a=10        #  pend campo cost
a=0.5       #  pot cubico Henon 
a=2         #  double well
a=3.1415    #  pend

      set xrange [-a:a]         
      set yrange [-a:a]
set arrow from  -a,0 to a,0    lw 1   lc rgb "black"      nohead
set arrow from  0,-a to 0,a    lw 1   lc rgb "black"      nohead
#      set logscale y 
#      set format y '10^{%L}'
       plot FILE    u  2:3  w  points      pt  1   lc   rgb "blue"   ps  0.2   t    '   '  #  ,\