//2012, 2013, 2014, 2015, 2016 Francesco Rossi, Stefano Sinigardi, BSD

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>

//#derivata nel tempo del punto dello spazio delle fasi X(t)=[x0,x1], oscillatore armonico
double df0_dt(const double x0, const double x1) //derivata 
{
	return x1;
}
double df1_dt(const double x0, const double x1)
{
	return -x0;
}

std::vector<double> euler(double dt, int nsteps)
{
	std::vector<double> X0,X1,norm; //teniamo a memoria tutta la traiettoria e la distanza in questi vettori
	X0.resize(nsteps+1);
	X1.resize(nsteps+1);
	norm.resize(nsteps+1);
	
	X0[0] = 1; //condizione iniziale
	X1[0] = 0;
	
	for(int n=0; n<nsteps; n++)
	{
		X0[n+1] =X0[n] + df0_dt(X0[n],X1[n])*dt; // DA FARE: completare utilizzando il metodo di eulero, usando la derivata df0_dt(X[n])
		X1[n+1] =X1[n] + df1_dt(X0[n],X1[n])*dt; // DA FARE: completare utilizzando il metodo di eulero, usando la derivata df1_dt(X[n])
	
		norm[n+1] = sqrt(X0[n+1]*X0[n+1]+X1[n+1]*X1[n+1]); //distanza da (0,0)
	}
	
	return norm;
}

std::vector<double> leapfrog(double dt, int nsteps)
{
	std::vector<double> X0,X1,norm; //teniamo a memoria tutta la traiettoria e la distanza in questi vettori
	X0.resize(nsteps+1);
	X1.resize(nsteps+1);
	norm.resize(nsteps+1);
	
	X0[0] = 1; //condizione iniziale
	X1[0] = 0;
	
	for(int n=0; n<nsteps; n++)
	{
		X0[n+1] =X0[n] + df0_dt(X0[n],X1[n])*dt + 0.5*df1_dt(X0[n],X1[n])*dt*dt;
		X1[n+1] =X1[n] + 0.5*(df1_dt(X0[n],X1[n]) + df1_dt(X0[n+1],X1[n+1]) )*dt; 
	
		norm[n+1] = sqrt(X0[n+1]*X0[n+1]+X1[n+1]*X1[n+1]); //distanza da (0,0)
	}
	
	return norm;
}

int main(void)
{
	//stampo le distanze dall'origine dopo 100000 iterazioni con i due metodi: quale sarà la più grande?
	std::vector<double> norm_euler, norm_leapfrog;
	int nsteps = 100000;
	double dt = 0.02;
	
	norm_euler = euler(0.02, nsteps);
	norm_leapfrog = leapfrog(0.02,nsteps);
	
	std::cout << norm_euler[nsteps] << "\n";
	std::cout << norm_leapfrog[nsteps] << "\n";
	
	std::ofstream output;	
	output.open("out.txt");
	
	for(int i=0; i<nsteps+1; i++)
	{
		
		output << i*dt << "\t" << norm_euler[i] 
			   		   << "\t" << norm_leapfrog[i] << std::endl; 	
	}
	
	output.close();
		
	//system("gnuplot plot_harm.plt");
	//system("xdg-open /home/alessandro/metnum/harm/confronto.png");
	
	return 0;
}

// ./a.out > out.txt
