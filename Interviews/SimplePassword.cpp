/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the Simple Password problem from a Eaton (Brossard) interview question using
//              Coderbyte (https://coderbyte.com/).
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

static const int PASSWORDLENGTHMIN = 7;
static const int PASSWORDLENGTHMAX = 31;
static const string INVALIDSTRING = "password";

bool HasInvalidString(string str) {
  // Transform the string in lower case
  for (int i = 0; i < str.length(); i++)
    str[i] = tolower(str[i]);
  // Will return true if it is a match to the invalid string.
  return str.compare(INVALIDSTRING) == 0;
}

string SimplePassword(string str) {
  int passwordLength = static_cast<int>(str.length());
  // Verify the password length
  if (passwordLength > PASSWORDLENGTHMIN && passwordLength < PASSWORDLENGTHMAX) {
    int cntCapital = 0, cntDigit = 0, cntPunctuation = 0;
    // Traverse the password string to see if it is valid
    for (int i = 0; i < passwordLength; i++) {
      // Alphabet letters
      if (isalpha(str[i])) {
        // Capitalized letter count
        if (isupper(str[i]))
          cntCapital++;
        // Check for the invalid string
        else if (passwordLength - i >=  INVALIDSTRING.length() && HasInvalidString(str.substr(i, INVALIDSTRING.length())))
          return string("false");
      }
      // Numeric character count
      else if (isdigit(str[i]))
        cntDigit++;
      // Punctuation character count
      else if (ispunct(str[i]))
        cntPunctuation++;
      // If not alphanumeric or punctuation characters, the password is rejected.
      else
        return string("false");
    }
    // If it has at least 1 capital letter, 1 digit and 1 punctuation, the password is accepted, if not it is rejected.
    return cntCapital > 0 && cntDigit > 0 && cntPunctuation > 0 ? string("true") : string("false");
  }
  // Password is rejected due to the invalid length
  else
    return string("false");
}

int main(void) {
  // keep this function call here
  cout << SimplePassword(coderbyteInternalStdinFunction(stdin));
  return 0;
}