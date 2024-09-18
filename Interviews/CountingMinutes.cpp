/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the Counting Minutes problem from a Eaton (Brossard) interview question using
//              Coderbyte (https://coderbyte.com/).
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

static const int MINUTES_IN_A_DAY = 60 * 24;

string CountingMinutes(string str) {

  // Split the string into 2 values of time
  int posDelimiter = str.find('-');
  string time1 = str.substr(0, posDelimiter);
  string time2 = str.substr(posDelimiter + 1);

  // Parse the string times
  posDelimiter = time1.find(':');
  int hour1   = stoi(time1.substr(0, posDelimiter));
  int minute1 = stoi(time1.substr(posDelimiter + 1, 2));
  bool isPM1  = time1[time1.length() - 2] == 'p';

  posDelimiter = time2.find(':');
  int hour2   = stoi(time2.substr(0, posDelimiter));
  int minute2 = stoi(time2.substr(posDelimiter + 1, 2));
  bool isPM2  = time2[time2.length() - 2] == 'p';

  // Normalize time in 24 hours period for easier computation
  if (isPM1 &&  hour1 < 12) {
    hour1 += 12;
  }
  else if (!isPM1 && hour1 == 12) {
    hour1 = 0;
  }
  if (isPM2 &&  hour2 < 12) {
    hour2 += 12;
  }
  else if (!isPM2 && hour2 == 12 && minute1 != 0) {
    hour2 = 0;
  }

  int totalMins1 = hour1 * 60 + minute1;
  int totalMins2 = hour2 * 60 + minute2;

  if (totalMins1 > totalMins2) {
    return to_string(MINUTES_IN_A_DAY - totalMins1 + totalMins2);
  }
  else {
    return to_string(totalMins2 - totalMins1);
  }
}

int main(void) {
  // keep this function call here
  cout << CountingMinutes(coderbyteInternalStdinFunction(stdin));
  return 0;
}