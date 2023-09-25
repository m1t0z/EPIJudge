#include "test_framework/generic_test.h"

long long SwapBits(long long x, int i, int j) {
  
  // If bits are equal then nothing to do.
  if(((x >> i) & 1) == ((x >> j) & 1))
  {
    return x;
  }

  // From here we know that bits are different.
  // Use XOR to swap bits:
  // - xor any bit with 1 => reverse it
  // - xor any bit with 0 => keeps it
  const auto mask = (1ll << i) | (1ll << j);
  return x ^ mask;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "i", "j"};
  return GenericTestMain(args, "swap_bits.cc", "swap_bits.tsv", &SwapBits,
                         DefaultComparator{}, param_names);
}
