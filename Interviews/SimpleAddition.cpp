/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the Simple Addition problem from a Eaton (Brossard) interview question using
//              Coderbyte (https://coderbyte.com/).
//              It is the Fibonacci suite implementation.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

int SimpleAddition(int num) {
  int sum = 1;
  for (int i = 2; i <= num; i++) {
    sum += i;
  }
  return sum;
}

int main(void) {
  // keep this function call here
  cout << SimpleAddition(coderbyteInternalStdinFunction(stdin));
  return 0;
}