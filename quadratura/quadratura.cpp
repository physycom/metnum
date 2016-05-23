//2012, 2013, 2014, 2015, 2016 Francesco Rossi, Stefano Sinigardi, BSD

#define _CRT_SECURE_NO_WARNINGS

#include <complex>
#include <cstdio>
#include <cmath>
#include <iostream>

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
	  // DA FARE
	}
	
	return sum;
}

double trapezi(double a, double b, int N)
{
	double sum = 0.0;
	double dx= (b-a)/N;
	
	for (int i=0;i<N;i++)
	{
	  // DA FARE
	}
	
	return sum;
}

double simpson(double a, double b, int N)
{
	//DA FARE
	return 0.0;
}

int main(void)
{
	FILE* f = fopen("out.txt","w"); //output
	
	double truth = 1.0-cos(1.0);
	
	for(int n=1; n<100; n++) //calcolo degli integrali con varie discretizzazioni(segmenti)
	{
		int N = n*n; //numero di segmenti
		fprintf(f,"%d %e %e %e\n",
			N,
			rettangoli(0.0, 1.0, N)-truth, //errore con il metodo dei rettangoli
			trapezi(0.0, 1.0, N)-truth,
			simpson(0.0, 1.0, N)-truth
			);
	}
		
	fclose(f);
}
