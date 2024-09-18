/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the Binary Converter problem from a Eaton (Brossard) interview question using
//              Coderbyte (https://coderbyte.com/).
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

string BinaryConverter(string str) {
  
  int valueDec = 0;
  int L = str.length() - 1;

  for (int i = L; i >= 0; i--) {
    valueDec += ((str[i] - '0') << (L - i));
  }
  return to_string(valueDec);
}

int main(void) { 
   
  // keep this function call here
  cout << BinaryConverter(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}