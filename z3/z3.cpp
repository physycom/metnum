//2012, 2013, 2014, 2015, 2016 Francesco Rossi, Stefano Sinigardi, BSD

#define _CRT_SECURE_NO_WARNINGS

#include <complex>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <stdlib.h>

//si compila con g++ z3.cpp
//esegue con ./a.out
//visualizza con python plot.py

typedef std::complex<double> num; //num == numero complesso

num f(const num & c) //f(x)
{
	return c*c*c-1.0;
}

num fd(const num & c) //sua derivata
{
	return 3.0*c*c; //DA fare scrivere - FATTO
}

int main(void)
{
	int N = 512;
	num* X = new num[N*N];       //array di coordinate
	double* R = new double[N*N]; //array per l'argomento
	
	for(int j=0; j<N; j++) //su griglia
		for(int i=0; i<N; i++)
		{
			double x = (i*1.0-N/2)/(N-1.0)*4.0;
			double y = (j*1.0-N/2)/(N-1.0)*4.0;
			
			X[i+j*N] = num(x,y); //inizializzazione griglia di coordinate
		}
	
	//num* X0 = X;
	
	for(int step=0; step<16; step++) //iterazioni del metodo di newton con partenza dai punti della griglia di numeri complessi X 
	{
		for(int j=0; j<N; j++) //su griglia
		{
			for(int i=0; i<N; i++)
			{
				num & x = X[i+j*N];
				x = x - f(x)/fd(x); //DA FARE: implementare il metodo di newton - FATTO
			}
		}
	}
	
	for(int j=0; j<N; j++) //su griglia
	{
		for(int i=0; i<N; i++)
		{
			R[i+j*N] = atan2(X[i+j*N].imag(), X[i+j*N].real()); //calcolo di arg(X)
		}
	}
	
	//FILE* o = fopen("out.bin","wb"); //dump su file, per visualizzarlo: python 
	//fwrite(R, sizeof(double)*N*N, 1, o);
	//fclose(o);
	
	std::ofstream output;	
	output.open("out.txt");
	

	for(int j=0; j<N; j++) //su griglia
	{
		for(int i=0; i<N; i++)
		{
			//output << X[i+j*N].real() << "\t"; 
			output << R[i+j*N] << "\t"; 
		}
		
		output << std::endl;
	}
	
	output.close();
	
	
	delete X;
	delete R;
	
	//system("gnuplot plot_z3.plt");
	//system("xdg-open /home/alessandro/metnum/z3/newton.png");
	
	return 0;
}
