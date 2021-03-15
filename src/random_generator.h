#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <random>
// random number generator from Stroustrup: 
// http://www.stroustrup.com/C++11FAQ.html#std-random
namespace random_generator
{
  extern std::random_device dev;
  extern std::mt19937 engine;
  int rand_int(int low, int high);
}
#endif