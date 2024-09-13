/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the Bracket Matcher problem from Coderbyte:
//              https://coderbyte.com/information/Bracket%20Matcher
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

string BracketMatcher(string str) {
  int openCnt = 0;

  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '(')
      openCnt++;
    else if (str[i] == ')') {
      openCnt--;
      if (openCnt < 0)
        return "0";
    }
  }
  return openCnt != 0 ? "0" : "1";
}

int main(void) { 
   
  // keep this function call here
  cout << BracketMatcher(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}