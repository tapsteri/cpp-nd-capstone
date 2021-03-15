#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <random>

namespace random_generator
{
  extern std::random_device dev;
  extern std::mt19937 engine;
  //extern std::uniform_int_distribution<int> random_dist;

  // random number generator from Stroustrup: 
// http://www.stroustrup.com/C++11FAQ.html#std-random

  int rand_int(int low, int high);
}
#endif