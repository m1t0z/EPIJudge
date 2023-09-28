#include "test_framework/generic_test.h"


// Requirements for allowed operators:
// - addition
// - subtraction
// - shifting
// Solution:
// - to speedup calculations subtract in loop `2^k * y` from x and its remaining.
int Divide(int x, int y) {
  
  int res = 0;
  
  while(x >= y) {
    int product = y;
    int cnt_y = 1;
    while(true)
    {
      auto new_product = static_cast<long long>(product) << 1;
      if(new_product > x) 
      {
        break;
      }
      
      product = new_product;
      cnt_y <<= 1;
    }
    x -= product;
    res += cnt_y;
  }

  return res;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_divide.cc", "primitive_divide.tsv",
                         &Divide, DefaultComparator{}, param_names);
}
