/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the Bracket Combinations problem from Coderbyte:
//              https://coderbyte.com/information/Bracket%20Combinations
//              My solution is actually the implementation of the Catalan Numbers computation.
//              I should change to the double type instead of the unsigned long long int type because the website cannot
//              handle big integers (i.e. anything bigger than 20!, so inputs greater than 10).
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

unsigned long long int Factorial(unsigned int n) {
  unsigned long long int f = 1;
  for (unsigned int i = 2; i <= n; i++) {
    f = f * static_cast<unsigned long long int>(i);
  }
  return f;
}

// Catalan numbers (2n)! / ((n+1)! * n!)
int BracketCombinations(int num) {
  return static_cast<int>(Factorial(2 * num) / Factorial(num + 1) / Factorial(num));
}

int main(void) { 
  // keep this function call here
  cout << BracketCombinations(coderbyteInternalStdinFunction(stdin));
  return 0;
}