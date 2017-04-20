
#define _CRT_SECURE_NO_WARNINGS
//  Inclusioni
#include <complex>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
// Fine inclusioni

/*  Integrazione con integratori simplettici dell'hamiltoniano del endolo modulato
   H= p^2/2  -  el*cos(x)*(1+eps*cos(ome*t))  che viene trasformato in un hamiltoniano
   indipendente  da t per usare gli integratori simplettici
   H= p_x^2/2 + p_y -el*cos(x)* (1+eps*cos(y))   
   questo nuovo hamiltoniano è integrale primo    
   L'errore viene stimato sulla variazione di H     
   err= 1-H(x,y,px,py)/H(x_0,y_0,px_0,py_0)
   
   Orbite regolari eps=0.02   caos debole eps=0.08  caos forte eps=0.2
 */


using namespace std;
double ome=1.;
double el=0.08;   // 0.02  regular     0.08 chaos  0.2 strong chaos 
double eps=1;
/* Hamiltoniano */
double H( double &x, double &y, double &px, double &py )   //  x, p non vengono aggiornate  &x, &p vengono aggiornate
{ double H, V; 
  //  pendolo  con modulazione temporale 
  V = - el*cos(x)*(1+eps*cos(ome*y));
  H= px*px/2 +  py + V;
  return H;}

/* Derivata potenziale rispetto a x  */
double Vx(double &x, double &y) 
{ double  Vx ;
  Vx= el*sin(x)*(1+eps*cos(ome*y));     // pendolo 
  return Vx;}

/* Derivata potenziale rispetto a y  */
double Vy(double &x, double &y) 
{ double  Vy ;
  Vy=  el*eps* ome*sin(ome*y)*cos(x);   // pendolo 
  return Vy;}

 
/* Integratore simplettico 2 */ 
void  sim2(double &x, double &y, double  &px,  double &py,  double dt)
 {   x=x+ dt/2*px;
     y=y+dt/2;
       
       px=px -dt*Vx(x,y);
       py=py -dt*Vy(x,y);
     
     x=x+dt/2*px;
     y=y+dt/2; }

/* Integratore simplettico 4 */ 
void  sim4(double &x, double &y, double &px,  double &py,  double dt)
{   double sq2, alpha, beta, dt1, dt2;
     sq2=pow(2., 1./3.);
     alpha= 1./(2.-sq2);
     beta= sq2/(2.-sq2);
     dt1= dt*alpha;
     dt2=-dt*beta;
     sim2(x,y,px,py,dt1);
     sim2(x,y,px,py,dt2);
     sim2(x,y,px,py,dt1);  }



// Integratore simplettico ordine 6 
 
void  sim6(double &x, double &y, double  &px, double &py,  double dt)
{   double sq2, alpha, beta, dt1, dt2;
     sq2=pow(2., 1./5.);
     alpha= 1./(2.-sq2);
     beta= sq2/(2.-sq2);
     dt1= dt*alpha;
     dt2=-dt*beta;
     sim4(x,y,px,py,dt1);
     sim4(x,y,px,py,dt2);
     sim4(x,y,px,py,dt1);  }
     
// Integratore simplettico ordine 8

void  sim8(double &x, double  &y,  double &px, double &py, double dt)
{   double sq2, alpha, beta, dt1, dt2;
     sq2=pow(2., 1./7.);
     alpha= 1./(2.-sq2);
     beta= sq2/(2.-sq2);
     dt1= dt*alpha;
     dt2=-dt*beta;
     sim6(x,y,px,py,dt1);
     sim6(x,y,px,py,dt2);
     sim6(x,y,px,py,dt1);  }  





 int  main( )
 { double x,  y, px,  py,    t ;
   double E0;
  int N_step=100;
  int N_per= 1000;    // numero periodi
  int k_max= N_per*N_step;   // numero totale time steps
  
  double  x0 ,  px0 , y0 , py0 ;
  double pi=4*atan(1.);
  double T_per=2*pi/ome;
  double  dt= T_per/N_step ;
  
  double a=0, b=pi;
  int Nx=20;
  double dx=(b-a)/Nx;
    ofstream  St  ("fort.1");  // apre il file  fort.1
    ofstream  St2 ("fort.2");  // apre il file  fort.2
    
    for(int ix=-Nx; ix< Nx ; ix++)
      {                                         //   ---------------------------->   loop   ix
	
	St  <<  "    "  <<  endl ;

	
	x0=a+dx*ix;
	px0=x0;
        y0=0;
	py0=0;
	
	
    x=x0;
    y=y0;
    px=px0;
    py=py0;

    cout   <<  setw  (18) << x0   <<   setw  (18) << px0   <<   endl;
  
    E0=H(x,y,px,py);
    
    t=0;
    
   
     for(int k=1; k<k_max ; k++)
       {                            //    ---------->  inizio loop k
	 
	 sim4(x,y,px,py,dt);     // chiamata a integratore 
	 

	 //	 sim2(x,y,px,py,dt);
      
      t=t+dt;
      int m_per=k/N_step;
      int ir=k-m_per*N_step -1;
      //    cout  << k <<  " k " <<  m_per  << " m per "  << ir <<  endl ;
      
                     if(ir<0) {	    // .......  inizio  if    periodo
	    //	cout  << k <<  "             k " <<  m_per  << "                     m per "  << ir <<  endl ;
	
        double E=H(x,y,px,py); 
	double er= abs(1-E/E0);

	//  si riportano le orbite tra -pi e pi 
	double duepi=2*pi;
        double xx=x/duepi;
        int  Int_xx=xx;
	xx=xx-Int_xx;
	if(xx>0.5)  {xx=xx-1;}
        if(xx<-0.5) {xx=xx+1;}
        xx=xx*duepi; 
	// fine riporto
  	
      
	//   cout   << m_per  <<  ir  << setw  (18) << scientific  << t  << endl ;
     
	St  << m_per  << setw  (18) << scientific << xx << setw  (18) << px  <<  setw  (18) << er  <<       endl ; //   setw  (18)  << E  << setw  (18)  << E0 <<   setw  (18)  << er  << endl;
      
      if(ix == 2) {
	St2   <<  m_per  <<    setw  (18) << scientific   << er  <<  	endl ;     }
      
		     }   // .........    fine  if    periodo
      
        }     //  <-----------   fine loop k 
        }   //    <--------------------------  fine loop ix         
      St.close();
      St2.close();
    }    // fine main 
