#include "test_framework/generic_test.h"
short Parity(unsigned long long x) {
  short cnt_bits = 0;
  while(x)
  {
    cnt_bits += x&1;
    x >>= 1;
  }

  return cnt_bits % 2;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
}
