/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the K Unique Characters problem from a Eaton (Brossard) interview question using
//              Coderbyte (https://coderbyte.com/).
//
// Problem: Have the function KUniqueCharacters(str) take the str parameter being passed and find the longest substring that
//          contains k unique characters, where k will be the first character from the string. The substring will start from
//          the second position in the string because the first character will be the integer k.
//
//          For example: if str is "2aabbacbaa" there are several substrings that all contain 2 unique characters,
//          namely: ["aabba", "ac", "cb", "ba"], but your program should return "aabba" because it is the longest substring.
//          If there are multiple longest substrings, then return the first substring encountered with the longest length.
//
//          k will range from 1 to 6.
//
//          Input: "3aabacbebebe"
//          Output: cbebebe
//
//          Input: "2aabbcbbbadef"
//          Output: bbcbbb
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string KUniqueCharacters(string str) {
  int K = str[0] - '0';
  unordered_map<char, int> hashMap;
  
  int left = 1, winStart = 1, length = 0, winLength = 0;
  for (int right = 1; right < str.length(); right++) {
    ++hashMap[str[right]];
    if (hashMap.size() <= K) {
      length = right - left + 1;
      if (length > winLength) {
        winStart = left;
        winLength = length;
      }
    }
    else {
      while (hashMap.size() > K) {
        --hashMap[str[left]];
        if (hashMap[str[left]] == 0) {
          hashMap.erase(str[left]);
        }
        left++;
      }
    }
  }
  return str.substr(winStart, winLength);
}

int main(void) {
  // keep this function call here
  cout << KUniqueCharacters(coderbyteInternalStdinFunction(stdin));
  return 0;
}