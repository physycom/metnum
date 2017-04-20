#include <cstdio>      /* printf, scanf, puts, NULL */
#include <ctime>
#include <random>

using namespace std;

int main ()
{
  double float_rand;
  mt19937 generator(time(NULL));
  // periodo: 2^19937 -1

  uniform_real_distribution<double> dist(0.0, 1.0);


  for(int i=0; i<10; i++) {
    double randomRealBetweenZeroAndOne = dist(generator);
    printf("%f\n", randomRealBetweenZeroAndOne);
  }
  return 0;

}

