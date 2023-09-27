#include "test_framework/generic_test.h"
#include <climits>

unsigned long long BitwiseSum(unsigned long long x, unsigned long long y)
{
  const auto width_in_bits = sizeof(x) * CHAR_BIT;
  
  auto res = 0ull;
  auto carry_bit = 0ull;
  for(int i = 0; i < width_in_bits; ++i)
  {
    const auto b1 = (x >> i) & 1;
    const auto b2 = (y >> i) & 1;

    auto res_bit = b1 ^ b2 ^ carry_bit;
    res |= (res_bit << i);

    // Set the carry bit if we have 2+ ONES in the current bit.
    carry_bit = b1&b2 | carry_bit&b1 | carry_bit&b2; 
  }

  if(carry_bit != 0)
  {
    throw std::overflow_error("Overflow!");
  }

  return res;
}

// Requirements:
//  - allowed operators: =, ==, all bitwise
//
// Solution idea: use "multiplication by column" method with binary representation.
//
unsigned long long Multiply(unsigned long long x, unsigned long long y) {
  
  auto res = 0ull;
  while(y)
  {
    if(y&1)
    {
      res = BitwiseSum(res, x);
    }

    x <<= 1;
    y >>= 1;
  }

  return res;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_multiply.cc",
                         "primitive_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
