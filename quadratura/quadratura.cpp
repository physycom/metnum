//2012, 2013, 2014, 2015, 2016 Francesco Rossi, Stefano Sinigardi, BSD

#define _CRT_SECURE_NO_WARNINGS

#include <complex>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <fstream>
#include <stdlib.h>

/*
g++ quadratura.cpp
./a.out
python plot.py
*/

double f(const double & x)
{
	return sin(x);
}

double rettangoli(double a, double b, int N) //integra f in [a,b] con N rettangoli
{
	double sum = 0.0;
	double dx  = (b-a)/N;
	
	for(int i=0; i<N; i++)
	{
	  sum += f(a + i*dx);
	}
	
	sum *= dx;
	
	return sum;
}

double trapezi(double a, double b, int N)
{
	double sum = 0.0;
	double dx= (b-a)/N;
	
	for (int i=0;i<N;i++)
	{
		sum += ( f(a + i*dx) + f(a + (i+1)*dx) );
	}
	
	sum *= 0.5*dx;
	
	return sum;
}

double simpson(double a, double b, int N)
{
	double sum = 0.0;
	double dx= (b-a)/N;
	
	for (int i=0;i<N;i++)
	{
		sum += f(a + i*dx) + 4.0*f(a + 0.5*((i+1)*dx + i*dx) ) + f(a + (i+1)*dx);
	}
	
	sum *= dx/6.0;
	
	return sum;
}

int main(void)
{
	//FILE* f = fopen("out.txt","w"); //output
	
	std::ofstream output;	
	output.open("out.txt");
		
	double truth = 1.0-cos(1.0);
	
	for(int n=1; n<100; n++) //calcolo degli integrali con varie discretizzazioni(segmenti)
	{
		int N = n*n; //numero di segmenti
	/*	fprintf(f,"%d %e %e %e\n",
			N,
			rettangoli(0.0, 1.0, N)-truth, //errore con il metodo dei rettangoli
			trapezi(0.0, 1.0, N)-truth,
			simpson(0.0, 1.0, N)-truth
			);
	*/
		
		output << N << "\t" << rettangoli(0.0, 1.0, N)-truth 
			        << "\t" << trapezi(0.0, 1.0, N)-truth 
			        << "\t" << simpson(0.0, 1.0, N)-truth << std::endl; 
	}
	
	
	output.close();
	//fclose(f);
	
	//system("gnuplot plot_quadratura.plt");
	//system("xdg-open /home/alessandro/metnum/quadratura/quadrature.png");
	
	return 0;
}
