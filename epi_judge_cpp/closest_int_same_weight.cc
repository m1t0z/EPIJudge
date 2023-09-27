#include "test_framework/generic_test.h"
#include <climits>

// Idea: iterate from LSB; find a pair of different neighbor bits; swap them.
unsigned long long ClosestIntSameBitCount(unsigned long long x) {
  
  int width_in_bits = sizeof(x) * CHAR_BIT;
  
  for(int i = 0; i < width_in_bits - 1; ++i)
  {
    const auto b1 = i;
    const auto b2 = i + 1;
    if(((x >> b1) & 1) != ((x >> b2) & 1))
    {
      // Different neighbor bits found! Swap them!
      const auto swap_mask = (1ull << b1) | (1ull << b2);
      x ^= swap_mask;
      break;
    }
  }

  return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "closest_int_same_weight.cc",
                         "closest_int_same_weight.tsv", &ClosestIntSameBitCount,
                         DefaultComparator{}, param_names);
}
