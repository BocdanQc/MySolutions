/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the Gas Station problem from a Eaton (Brossard) interview question using
//              Coderbyte (https://coderbyte.com/).
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Station {
  int gasReserve;
  int gasToContinue;
  Station()             : gasReserve(0), gasToContinue(0) { }
  Station(int g, int c) : gasReserve(g), gasToContinue(c) { }
  Station(string s)     : gasReserve(0), gasToContinue(0) {
    size_t delimiterPos = s.find(':');
    if (delimiterPos != string::npos) {
        gasReserve    = stoi(s.substr(0, delimiterPos));
        gasToContinue = stoi(s.substr(delimiterPos + 1));
    }
  }
};

string GasStation(string strArr[], int arrLength) {
  map<int, Station> stations;
  int nbStations = stoi(strArr[0]);

  for (int i = 1; i <= nbStations; i++)
    stations[i] = Station(strArr[i]);

  for (int i = 1; i <= nbStations; i++) {
    int gasCurr = stations[i].gasReserve;
    int gasNext = stations[i].gasToContinue;
    int nbVisited = 1;
    while (nbVisited != nbStations) {
      if (gasCurr < gasNext)
        break;
      int nextIdx = (i + nbVisited) % (nbStations + 1);
      gasCurr += stations[nextIdx].gasReserve - gasNext;
      gasNext = stations[nextIdx].gasReserve;
      nbVisited++;
    }
    if (nbVisited == nbStations)
      return to_string(i);
  }
  return string("impossible");
}

int main(void) {
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << GasStation(A, arrLength);
  return 0;
}