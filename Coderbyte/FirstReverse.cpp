/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the First Reverse problem from Coderbyte:
//              https://coderbyte.com/information/First%20Reverse
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

string FirstReverse(string str) {
  int half = str.length() >> 1;
  int last = str.length() - 1;
  char temp;

  for (int i = 0; i < half; i++) {
    temp = str[i];
    str[i] = str[last - i];
    str[last - i] = temp;
  }
  return str;
}

int main(void) {
  // keep this function call here
  cout << FirstReverse(coderbyteInternalStdinFunction(stdin));
  return 0;
}