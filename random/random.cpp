#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main ()
{
  int int_rand;
  double float_rand;

  /* initialize random seed: */
  srand (time(NULL));

  for(int i=0; i<10; i++) {
    int_rand = rand();
    float_rand = double(rand())/RAND_MAX;
    // periodo 2^32
    
    printf("%i\t%f\n", int_rand, float_rand);
  };

  return 0;
}


