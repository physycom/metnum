#include <complex>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <fstream>
//#define HARDCODED
// scommentare il precedente define per usare parametri codificati direttamente nel sorgente



double dammi_rumore_bianco(const double min, const double max)
{ 
	double rumore = (rand());
	// rinormalizzarlo e spostarlo nell'intervallo corretto
	return rumore;
}

double Vprimo(const double x)
{
	return x;	// sostituire con un V' corretto
}

void evo(double * x, const double dt, const double gamma, const double epsilon)
{
	double rumore=dammi_rumore_bianco(-0.5, +0.5);
	// scrivere qui l'algoritmo
}




int main(void)
{
	double * particelle;
	double gamma, epsilon, dt, x0, p0;
	int nparticelle, nsteps, nout;
	std::ofstream evostream("evo.txt");
	srand (time(NULL));   

#ifndef HARDCODED
	std::cout << "Equazione di Langevin" << std::endl;

	std::cout << "Dimmi quante particelle vuoi evolvere: ";
	std::cin >> nparticelle;

	std::cout << "Dimmi la loro posizione iniziale: ";
	std::cin >> x0;
	std::cout << "Dimmi il loro impulso iniziale: ";
	std::cin >> p0;



	std::cout << "Dammi il fattore di damping: ";
	std::cin >> gamma;

	std::cout << "Dammi l'epsilon: ";
	std::cin >> epsilon;

	std::cout << "Dammi il dt: ";
	std::cin >> dt;
	t = 0.0;

	std::cout << "Dammi il numero di steps: ";
	std::cin >> nsteps;
	//  std::cout << "Dammi il numero di output che vuoi avere: ";
	//  std::cin >> nout;
	nout = 16;

#else
	gamma = 0.0;
	epsilon = 0.0;
	dt = 0.0;
	x0 = 0.0;
	p0 = 0.0;
	nsteps = 10;
	nparticelle = 1;
	nout = 16;
	t = 0.0;
#endif


	// inizializzazione particelle
	particelle = new double[2*nparticelle];
	for (int i = 0; i < nparticelle; i++)
	{
		particelle[2*i] = x0;
		particelle[2*i+1] = p0;
	}

	int macrostep = nsteps / nout;

	for (int k = 0; k < nout; k++)
	{
		for (int i = 0; i < nparticelle; i++)
		{
			evostream << particelle[2*i] << "\t" << particelle[2*i+1] << std::endl;
		}

		for (int j = 0; j < macrostep; j++)
		{
			for (int i = 0; i < nparticelle; i++)
			{
				evo(particelle+2*i, dt, gamma, epsilon);
			}
			t += dt;
		}
	}

	std::stringstream ss;
	ss << "python plot_mc.py "<<nparticelle << "\n";
	system(ss.str().c_str());

	//#if defined(_WIN32) || (_WIN64)
	//  std::cin.get(); 
	//#endif

	return 0;
}

