
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


/* Integrazione di Hamiltoniai H=p?2/2 +V(x) 
   con integratori simplettici di vario ordine.
   Si plottano le orbite e si calcola l'errore sulla
   energia.

   Per cambiare potenziale scommentare nelle funzioni H e Vp
 */


/* Hamiltoniano */
double H( double &x, double &p)   //  x, p non vengono aggiornate  &x, &p vengono aggiornate
{ double H, V;
 
          V= -x*x/2 + x*x*x*x/4;    // doppia buca
  //         V=  x*x/2 + x*x*x/3 + 0.1*x*x*x*x/4;      // pot.cubico
  //	    V= 1  -  cos(x);                  //pendolo
  //	    V= -x-4*cos(x);                  //pendolo con campo costante
  H= p*p/2 + V;
  return H;}

/* Derivata potenziale  */
double Vp(double &x) 
{ double  Vp ;
       Vp= -x + x*x*x;   // doppia buca
  //         Vp= x +  x*x +  0.1*x*x*x ;   // pot. cubico
  //       Vp=  sin(x);      // pendolo
  //     Vp= -1 + 4*sin(x);      // pendolo con campo costante
  return Vp;}

/* Integratore simplettico 1  */ 
void  sim1(double &x, double  &p,  double dt)
 {
   // cout   << setw  (18) << scientific << x << setw  (18) << p  << endl ;
   //cout   <<  scientific <<  setw  (18) <<  x <<  setw  (18) <<  p  << endl ;
   x=x+ dt*p;
   p=p -dt*Vp(x);
 }
 
/* Integratore simplettico 2 */ 
void  sim2(double &x, double  &p,  double dt)
 {   x=x+ dt/2*p;
     p=p -dt*Vp(x);
     x=x+dt/2*p;}

/* Integratore simplettico 4 */ 
void  sim4(double &x, double  &p,  double dt)
{   double sq2, alpha, beta, dt1, dt2;
     sq2=pow(2., 1./3.);
     alpha= 1./(2.-sq2);
     beta= sq2/(2.-sq2);
     dt1= dt*alpha;
     dt2=-dt*beta;
     sim2(x,p,dt1);
     sim2(x,p,dt2);
     sim2(x,p,dt1);  }


/* Integratore simplettico 6 */ 
void  sim6(double &x, double  &p,  double dt)
{   double sq2, alpha, beta, dt1, dt2;
     sq2=pow(2., 1./5.);
     alpha= 1./(2.-sq2);
     beta= sq2/(2.-sq2);
     dt1= dt*alpha;
     dt2=-dt*beta;
     sim4(x,p,dt1);
     sim4(x,p,dt2);
     sim4(x,p,dt1);  }

/* Integratore simplettico 8 */ 
void  sim8(double &x, double  &p,  double dt)
{   double sq2, alpha, beta, dt1, dt2;
     sq2=pow(2., 1./7.);
     alpha= 1./(2.-sq2);
     beta= sq2/(2.-sq2);
     dt1= dt*alpha;
     dt2=-dt*beta;
     sim6(x,p,dt1);
     sim6(x,p,dt2);
     sim6(x,p,dt1);  }





 int  main( )
 { double x,  p, x2, p2, x4, p4, x6, p6, x8, p8, t ;
   double E0;
   int N=100;                    // passi per periodo 
  double  x0 ,  p0=0. ;
  double pi=4*atan(1.);
  double  dt= 2.*pi/N ;
  double  a=-10,  b=10;    //    pend. con campo costante
  a=-pi,  b=pi;            //    pendolo
  //  a=-2 ,  b=2;             //    doppia buca  e pot cubico
  int Nx=40;
  double dx=(b-a)/Nx;
    ofstream  St  ("fort.1");  // apre il file  fort.1
    ofstream  St2 ("fort.2");  // apre il file  fort.2
    
    for(int ix=1; ix< Nx+1  ; ix++)
      {    // loop   ix
	x0=a+dx*(ix-1);
        cout   << ix  <<  setw(18) <<   x0  << endl ;
    x=x0;	
    p=p0;
    E0=H(x0,p0);
    x2=x0;
    p2=p0;
    x4=x0;
    p4=p0;
    x6=x0;
    p6=p0;
    x8=x0;
    p8=p0;
    t=0;
    
    
     
     for(int k=1; k<3*N ; k++)
       {      // loop k
      sim1(x,p,dt);
      sim2(x2,p2,dt);
      sim4(x4,p4,dt);
      sim6(x6,p6,dt);
      sim8(x8,p8,dt);

      t=t+dt;
      double er= 1-H(x,p)/E0;
      double er2=1-H(x2,p2)/E0;
      double er4=1-H(x4,p4)/E0;
      double er6=1-H(x6,p6)/E0;
      double er8=1-H(x8,p8)/E0;
      double E2= H(x2,p2);
      double err2= 1-E2/E0;
     
      St  <<  setw(10) << t  << setw  (18) << scientific << x4 << setw  (18) << p4  <<  endl;
      
      if(ix==2 ) {
      St2   <<  ix  << setw(18) << t  <<   setw  (18) << scientific   << er   <<   setw  (18) << er2  <<  setw  (18) << er4
	      << setw  (18) << er6  << setw  (18) << er8  <<	endl ;  }
      
      }     // loop k 
        }   // loop ix         
      St.close();
      St2.close();
    }    // fine main 
