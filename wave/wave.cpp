//2012, 2013, 2014, 2015, 2016 Francesco Rossi, Stefano Sinigardi, BSD

#define _CRT_SECURE_NO_WARNINGS

#include <complex>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

#ifndef M_PI
#define M_PI 3.14159
#endif

typedef double* field;

field E;
field B;
field E0;

double f(const double & phase)
{
	double x0 = 5;
	double sigma = 2;
	double lambda = 1.0;
	
	double d = phase-x0;
	//TODO modulare per il profilo gaussiano exp(-(d*d)/(sigma*sigma))*
	return cos(d*2.0*M_PI/lambda);
}

template<int STAGGER>
double go(int N)
{
	double L  = 40.0;
	double dx = L/N;
	double dt = dx*(1.5 /*...*/); //TODO implementare CFL: 1.5 è instabile
	
	E = new double[N]; //leapfrog: al tempo t
	B = new double[N]; //al tempo t+1/2
	E0 = new double[N];//iniziale
	
	for(int i=0; i<N; i++)
	{
		double x = i*dx;
		E0[i] = E[i] = f(x);
		B[i] = f(x-dt*0.0-dx*0.0); //TODO sistemare la definizione spaziale e temporale di B
	}
	
	FILE* out=fopen("wave.bin","wb");
	
	//
	std::cout << L/dt << "\n";
	int Nt = ((int)(L/dt))*2;
	int t=0;
	for(t=0; t<Nt+1; t++) //TODO sistemare il numero di passi per il caso staggered
	{
		if(t % (Nt/4) == 0)
		{
			fwrite(E,sizeof(double),N,out);
		}
		
		if(STAGGER == 0) //no stagger
		{ 
			for(int i=1; i<N-1; i++) //passo avanzamento E
			{
				//TODO implementare le differenze finite 
				//E[i] = E[i] - (B[i+...] - B[i-...])*(...); //TODO
			}
			//TODO implementare periodic boundary conditions E
			
			//E[0  ] = E[0  ] - (B[...] - B[N-1])*(...);
			//E[N-1] = ...;
			
			for(int i=1; i<N-1; i++) //passo avanzamento B
			{
				// B[i] = ... TODO
			}
			//TODO implementare periodic boundary conditions B
			//B[0  ] = ...;
			//B[N-1] = ...;
		}
		else
		{
			//TODO implementare il caso staggered qui
		}
		
	}
	
	//if(t >= Nt)
	//{
		//calcolo errore
		double delta = 0.0;
		for(int i=0; i<N; i++)
		{
			double d = E[i]-E0[i];
			delta += d*d;
		}
		delta = sqrt(delta)/N;
		std::cout << "N= "<< N << " delta="<< delta << " t="<<(t-1)*dt<< " STAGGER="<<STAGGER<< "\n";
	//}
	
	fclose(out);
		
	
	delete E;
	delete B;
	delete E0;
	return delta;
}
int main(void)
{

	
	int N = 128;
	FILE* out = fopen("scaling.txt","w");
	
	for(int i=0; i<5; i++)
	{
		N *= 2;
		double rn = go<0>(N);
		double rs = go<    0    >(N);
		
		fprintf(out, "%lf\t%lf\t%lf\n", (double)N, rn, rs);
	}
	
	fclose(out);
	//
	std::stringstream ss;
	ss << "python plot_wave.py "<<N << "\n";
	system(ss.str().c_str());
}
