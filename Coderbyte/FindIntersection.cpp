/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the Find Intersection problem from Coderbyte:
//              https://coderbyte.com/information/Find%20Intersection
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

string FindIntersection(string strArr[], int arrLength) {
  string strRes = "false";

  string str1 = strArr[0];
  string str2 = strArr[1];
  int pos1 = 0, pos2 = 0;
  int val1 = 0, val2 = 0;

  while (pos1 != std::string::npos || pos2 != std::string::npos) {
    pos1 = str1.find(',');
    val1 = stoi(str1.substr(0, pos1));
    pos2 = str2.find(',');
    val2 = stoi(str2.substr(0, pos2));

    if (val1 < val2) {
      if (pos1 == std::string::npos)
        break;
      str1.erase(0, pos1 + 1);
    }
    else if (val1 > val2) {
      if (pos2 == std::string::npos)
        break;
      str2.erase(0, pos2 + 1);
    }
    else if (val1 == val2) {
      if (strRes.compare("false") == 0) {
        strRes = to_string(val1);
      }
      else {
        strRes += string(",") + to_string(val1);
      }
      if (pos1 == std::string::npos || pos2 == std::string::npos)
        break;
      str1.erase(0, pos1 + 1);
      str2.erase(0, pos2 + 1);
    }
  }
  return strRes;
}

int main(void) {
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << FindIntersection(A, arrLength);
  return 0;
}