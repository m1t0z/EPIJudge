#include "test_framework/generic_test.h"


// Requirements:
// - ignore underflow/overflow
double Power(double x, int y) {
  
  // Handle negative power.
  if(y < 0)
  {
    x = 1.0/x;
    y = -y;
  }
  
  auto res = 1.0;
  while(y)
  {
    if(y & 1)
    {
      res *= x;
    }

    // The main performance trick: instead of multiplying `x` the `y` number of times
    // reduce the `y` and increase the x:
    // - each reduce of `y` by 2 is equal to `x^2`
    x *= x;
    y >>= 1;
  }

  return res;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "power_x_y.cc", "power_x_y.tsv", &Power,
                         DefaultComparator{}, param_names);
}
