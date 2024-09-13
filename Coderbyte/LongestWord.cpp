/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the Longest Word problem from Coderbyte:
//              https://coderbyte.com/information/Longest%20Word
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string LongestWord(string sen) {
  string wordLongest = "";
  for (int i = sen.length() - 1; i >= 0; i--) {
    if (!isalnum(sen[i]) && sen[i] != ' ' ) {
      sen.erase(sen.begin() + i);
    }
  }

  size_t pos = 0;
  std::string wordCurr;
  do {
    pos = sen.find(' ');
    wordCurr = sen.substr(0, pos);
    if (wordCurr.length() > wordLongest.length()) {
      wordLongest = wordCurr;
    }
    sen.erase(0, pos + 1);
  } while (pos != std::string::npos);
  return wordLongest;
}

int main(void) {
  // keep this function call here
  cout << LongestWord(coderbyteInternalStdinFunction(stdin));
  return 0;
}