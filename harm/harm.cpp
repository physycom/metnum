//2012, 2013, 2014, 2015 Francesco Rossi, Stefano Sinigardi, BSD

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

//#derivata nel tempo del punto dello spazio delle fasi X(t)=[x0,x1], oscillatore armonico
double df0_dt(const double x0, const double x1) //derivata 
{
	return x1;
}
double df1_dt(const double x0, const double x1)
{
	return -x0;
}

double euler(double dt, int nsteps)
{
	std::vector<double> X0,X1,norm; //teniamo a memoria tutta la traiettoria e la distanza in questi vettori
	X0.resize(nsteps+1);
	X1.resize(nsteps+1);
	norm.resize(nsteps+1);
	
	X0[0] = 1; //condizione iniziale
	X1[0] = 0;
	
	for(int n=0; n<nsteps; n++)
	{
		X0[n+1] =X0[n] + 0; // DA FARE: completare utilizzando il metodo di eulero, usando la derivata df0_dt(X[n])
		X1[n+1] =X1[n] + 0; // DA FARE: completare utilizzando il metodo di eulero, usando la derivata df1_dt(X[n])
	
		norm[n+1] = sqrt(X0[n+1]*X0[n+1]+X1[n+1]*X1[n+1]); //distanza da (0,0)
	}
	
	return norm[nsteps];
}

double leapfrog(double dt, int nsteps)
{
	// DA FARE: completare utilizzando il metodo leapfrog, usando la derivata df0_dt,df1_dt
	
	return 0;
}

int main(void)
{
	//stampo le distanze dall'origine dopo 100000 iterazioni con i due metodi: quale sarà la più grande?
	std::cout << euler(0.02, 100000) << "\n";
	std::cout << leapfrog(0.02,100000)<< "\n";
	
	return 0;
}