
#define _CRT_SECURE_NO_WARNINGS
//  Inclusioni
#include <complex>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
// Fine inclusioni
using namespace std;

/*  Integra con Runge-Kutta la doppia buca  con  dipendenza periodica dal tempo.
    Si fa l'analisi stroboscopica tracciando i punti ad ogni periodo.
    Quando tale dipendenza nonc'è eps=0 si valut al'integrale primo e si vede che 
    l'errore su H cresce in modo monotono */


double ome=1.;
double el=0.02;    // variabili globali
double eps=0.;    //   0 no dip tempo,  0.02 quasi regolare 0.05 caos debole   0.2 caos forte 



void Phi(double &t, double &x,  double &p, double &fx, double &fp)
{  fx = p ;
  fp = x -x*x*x *(1+eps*cos(ome*t));} 

void Kutta(double &xx,  double &yy, double  &t, double dt)
{ double K1[3], K2[3], K3[3], K4[3];
  double fx, fy, x, y;
 
  x=xx;
  y=yy;
  Phi( t, x, y, fx, fy);    
  K1[1]= fx;
  K1[2]= fy;


  
  double h=0.5*dt;
  double t1=t+h ;
  x=xx+ h*K1[1];
  y=yy+ h*K1[2];  
  Phi( t1, x, y, fx, fy);
  K2[1]= fx;
  K2[2]= fy;   

   x=xx+ h*K2[1];
   y=yy+ h*K2[2];
   Phi( t1, x, y, fx, fy); 
   K3[1]= fx;
   K3[2]= fy;

   double t2=t+dt;

   x=xx+ dt*K3[1];
   y=yy+ dt*K3[2];
   Phi( t2, x, y, fx, fy); 
   K4[1]= fx;
   K4[2]= fy;

   xx=xx +  (K1[1]+2*K2[1] +2*K3[1] +K4[1] ) *dt/6 ;
   yy=yy +  (K1[2]+2*K2[2] +2*K3[2] +K4[2] ) *dt/6 ;
   t=t+dt;
   
   //  cout << setw(18) << t  << setw(18) << xx   << setw(18) <<yy  << endl ;
   // cout << "      " << endl;
  
             }
   



/* Hamiltoniano */
double H( double &x, double &p )   //  x, p non vengono aggiornate  &x, &p vengono aggiornate
{ double H, V; 
  //  Hamiltoniano potenziale a  doppia buca 
  V = -x*x/2 + x*x*x*x/4;
  H= p*p/2 + V;
  return H;}


  


 int  main( )
 { double x, p ,    t ;
   double E0;
   int N_step=100;     // passi per periodo
  int N_per= 1000;     // numero periodi
  int k_max= N_per*N_step;   // numero totale time steps
  
  double  x0 ,  p0 ;    // condizioni inizilai 
  double pi=4*atan(1.);
  double T_per=   2*pi/ome;
  double  dt= T_per/N_step  ; //  *sqrt(2.) ; 
  
  double a=-2, b=2;
  int Nx=20;
  double dx=(b-a)/Nx;
    ofstream  St  ("fort.1");  // apre il file  fort.1
    ofstream  St2 ("fort.2");  // apre il file  fort.2
    
    for(int ix=1; ix< Nx ; ix++)
      {                                         //   ---------------------------->   loop   ix cond. iniz. 

	t=0;
	St  <<  "    "  <<  endl ;
		
	x0=a+dx*ix ;
	p0=x0*0.2; 
       		
    x=x0;
    p=p0;

    St   << setw(18) << t    << setw  (18) << scientific << x << setw  (18) << p  << endl;

    cout   <<  setw  (18) << x0   <<   setw  (18) << p0   <<   endl;
  
    E0=H(x,p);
    
    t=0;
    
   
     for(int k=1; k<k_max ; k++)
       {                            //    ---------->  inizio loop k   per evol. temporale
	
	 Kutta(x,p,t,dt);     // chiamata a integratore 
	 

	
      int m_per=k/N_step;
      int ir=k-m_per*N_step  ;
     
   
         if(ir==0) {    // .......  inizio  if    per analisi stroboscopica 
	   
	
        double E=H(x,p); 
	double er= abs(1-E/E0);
	double xx=x;

	/*  si riportano le orbite tra -pi e pi 
	double duepi=2*pi;
        double xx=x/duepi;
        int  Int_xx=xx;        //    questo serve solo per il pendolo
	xx=xx-Int_xx;
	if(xx>0.5)  {xx=xx-1;}
        if(xx<-0.5) {xx=xx+1;}
        xx=xx*duepi; 
            //   fine riporto	*/     
  	
      
	//   cout   << m_per  <<  ir  << setw  (18) << scientific  << t  << endl ;
     
	St   << setw(18) << t    << setw  (18) << scientific << xx << setw  (18) << p  <<  setw  (18) << er  << setw(18) << t   <<     endl ;  
       
      if(ix == 3) {
	St2   << setw(18) << t    <<    setw  (18) << scientific   << er  <<  	endl ;     }
      
      	     }   // .........    fine  if    periodo
      
        }     //  <-----------   fine loop k 
        }   //    <--------------------------  fine loop ix         
      St.close();
      St2.close();
    }    // fine main 
