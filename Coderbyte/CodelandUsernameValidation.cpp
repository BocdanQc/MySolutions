/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the Codeland Username Validation problem from Coderbyte:
//              https://coderbyte.com/information/Codeland%20Username%20Validation
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string CodelandUsernameValidation(string str) {
  if (str.length() < 4 || str.length() > 25) return string("false");
  if (!isalpha(str[0])) return string("false");
  if (str.back() == '_') return string("false");
  for (int i = 1; i < str.length(); i++) {
    if (!isalpha(str[i]) && !isdigit(str[i]) && str[i] != '_') {
      return string("false");
    }
  }
  return string("true");
}

int main(void) {
  // keep this function call here
  cout << CodelandUsernameValidation(coderbyteInternalStdinFunction(stdin));
  return 0;
}