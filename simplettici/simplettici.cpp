//2012, 2013, 2014, 2015, 2016 Francesco Rossi, Stefano Sinigardi, BSD


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

struct harmonic_osc
{
	double V(const double q, const double t) //potenziale
	{
		return 0.5*q*q;
	}
	double minus_gradV(const double q, const double t) 
	{
		return -q;
	}
	double ci_q() //condizioni iniziali
	{
		return 1.0;
	}
	double ci_p()
	{
		return 0.0;
	}
	double analytic_q(double T) //soluzione analitica
	{
		return cos(T);
	}
	double analytic_p(double T)
	{
		return -sin(T);
	}
};

struct quartic_osc
{
	double V(const double q, const double t)
	{
		return 0.5*q*q+q*q*q*q;
	}
	double minus_gradV(const double q, const double t)
	{
		return 0.0;//TODO
	}
	double ci_q()
	{
		return 1.0;
	}
	double ci_p()
	{
		return 0.0;
	}
	double analytic_q(double T)
	{
		return 0;
	}
	double analytic_p(double T)
	{
		return 0;
	}
};

//TODO aggiungere strutture per altri problemi (corpo gravitazionale,altri oscillatori)

template<class PROBLEM>
void advance_1storder(double & q_new, double & p_new, const double q, const double p, const double dt, const double t, PROBLEM & problem)
{
	//TODO implementare l'integratore al primo ordine corretto (c'e' un errore)
	p_new = p + dt*problem.minus_gradV(q,t);
	q_new = q + dt*p_new;
}

template<class PROBLEM>
void advance_2ndorder(double & q_new, double & p_new, const double q, const double p, const double dt, const double t, PROBLEM & problem)
{
	//TODO implementare l'integratore al secondo ordine 
	q_new = 0;
	p_new = 0;
}

template<class PROBLEM>
void advance_4thorder(double & q_new, double & p_new, const double q, const double p, const double dt, const double t, PROBLEM & problem)
{
	//TODO implementare l'integratore al quarto ordine 
	q_new = 0;
	p_new = 0;
}

int main(void)
{
	harmonic_osc problem;
	int N_tries=8;
	
	for(int n_=1; n_<N_tries; n_++)
	{
		int n = 2*n_-1; //prova con vari passi di integrazione
		int steps = 1024*n;
		double dt = 0.1/n;
		double t  = 0;
		
		std::vector<double> q(steps);
		std::vector<double> p(steps);
		std::vector<double> E(steps);
		
		q[0] = problem.ci_q();
		p[0] = problem.ci_p();
		
		double Error;
		
		for(int i=0; i<steps-1; i++)
		{
			advance_1storder(q[i+1], p[i+1], q[i], p[i], dt, t, problem); // per quello al primo ordine!
			
			Error += pow(problem.analytic_q(t)-q[i],2.0);
			Error += pow(problem.analytic_p(t)-p[i],2.0);
			
			t += dt;
			
			E[i+1] = 0.5*p[i+1]*p[i+1] + problem.V(q[i+1],t);
			//TODO calcolare escursione energia per i vari integratori
			


		}
		Error /= steps;
		
		std::cout << n << " " << Error << "\n"; //stampa l'errore per numero di passi n
	}
	
	return 0;
}
//prendi H=p^2/2 + V(q)*f(wt)
//con f periodica nel tempo con freq w
//verifico che se prendo H'=p^2/2+wj+V(q)*f(fi)
//fi punto=w
//j ounto= dH'/dfi
