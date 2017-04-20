g++ -o eq_diff_Kutta.exe eq_diff_Kutta.cpp 
./eq_diff_Kutta.exe
gnuplot  Plot_eq_diff_orbits.plt
display  Fig.png &
gnuplot  Plot_eq_diff_Kutta_er.plt
display  Fig2.png &
