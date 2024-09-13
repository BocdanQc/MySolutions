/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the First Factorial problem from Coderbyte:
//              https://coderbyte.com/information/First%20Factorial
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

int FirstFactorial(int num) {
  int factorial = 1;
  if (num > 0) {
    for (int i = 2; i <= num; i++) {
      factorial *= i;
    }
  }
  return factorial;

}

int main(void) { 
  // keep this function call here
  cout << FirstFactorial(coderbyteInternalStdinFunction(stdin));
  return 0;
}