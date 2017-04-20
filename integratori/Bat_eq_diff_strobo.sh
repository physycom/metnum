g++ -o eq_diff_strobo.exe eq_diff_strobo.cpp 
./eq_diff_strobo.exe
gnuplot  Plot_eq_diff_orbits.plt
display  Fig.png &
gnuplot  Plot_eq_diff_strobo_2.plt
display  Fig2.png &
