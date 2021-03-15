#include <random>

namespace random_generator
{
  std::random_device dev;
  std::mt19937 engine;

    int rand_int(int low, int high)
    {
      static std::default_random_engine re {};
      using Dist = std::uniform_int_distribution<int>;
      static Dist uid {};
      return uid(re, Dist::param_type{low,high});
    }
}

