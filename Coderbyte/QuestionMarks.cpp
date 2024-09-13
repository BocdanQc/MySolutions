/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solutions to the Question Marks problem from Coderbyte:
//              https://coderbyte.com/information/Questions%20Marks
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string QuestionsMarks(string str) {
  string answer = "false";
  int prev = 0;
  int qCnt = 0;

  for (int i = 0; i < str.length(); i++) {
    if (isdigit(str[i])) {
      if (prev + str[i] - '0' == 10) {
          if (qCnt == 3)
            answer = "true";
          else
            return "false";
      }
      prev = str[i] - '0';
      qCnt = 0;
    }
    else if (str[i] == '?') {
      qCnt++;
    }
  }
  return answer;
}

int main(void) { 
  // keep this function call here
  cout << QuestionsMarks(coderbyteInternalStdinFunction(stdin));
  return 0;
}