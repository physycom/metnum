#!/gnuplot
FILE_IN='out.txt'

FILE_OUT='newton.png'

set terminal png enhanced
set output FILE_OUT
set xlabel 'x' 
set ylabel 'px'

#set palette rgbformula -7,2,-7
set cbrange [-0.5:1]
set cblabel "Score"
#unset cbtics

set xrange [-0.5:512.5]
set yrange [-0.5:512.5]

#$map1 << FILE_IN

set view map
splot FILE_IN matrix with image
