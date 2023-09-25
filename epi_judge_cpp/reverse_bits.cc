#include "test_framework/generic_test.h"
#include <climits>

unsigned long long ReverseBits(unsigned long long x) {
  
  // Sanity check: expected size of the input variable in bits.
  static_assert(sizeof(x) * CHAR_BIT == 64);

  auto rev = 0ull;
  int counter = 0;
  while(counter++ < 64){
    rev <<= 1;
    rev |= x&1;
    x >>= 1;
  }
  
  return rev;  
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_bits.cc", "reverse_bits.tsv",
                         &ReverseBits, DefaultComparator{}, param_names);
}
