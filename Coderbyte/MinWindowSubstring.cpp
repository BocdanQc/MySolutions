/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solutions to the Min Window Substring problem from Coderbyte:
//              https://coderbyte.com/information/Min%20Window%20Substring
//              set vs unordered_map vs array of int for 256 characters
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <set>

using namespace std;

// Solution using multiset
string MinWindowSubstring(string strArr[], int arrLength) {
  string strN = strArr[0]; multiset<char> setN;
  string strK = strArr[1]; multiset<char> setK;
  
  // Store the occurrences of characters of string K
  for (auto it = strK.begin(); it != strK.end(); it++)
    setK.insert(*it);

  int left = 0, winStart = 0, winLength = strN.length() + 1;
  int count = 0;

  // Traverse the N string 
  for (int right = 0; right < strN.length(); right++) {
    setN.insert(strN[right]);
    if (setK.count(strN[right]) > 0 && setN.count(strN[right]) <= setK.count(strN[right]))
      count++;

    // If all string K characters are accounted for in the current string N substring
    if (count == strK.length()) {
      // Try to minimize the window i.e., check if any character is occurring more no. of times than its occurrence in pattern, 
      // if yes then remove it from starting and also remove the useless characters. 
      while (setK.count(strN[left]) == 0 || setN.count(strN[left]) > setK.count(strN[left]))
      { 
          if (setN.count(strN[left]) > setK.count(strN[left])) 
              setN.erase(setN.find(strN[left])); // To remove only 1 key, use "extract" instead in C++17
          left++; 
      } 

      // update window size 
      int len = right - left + 1; 
      if (winLength > len) 
      { 
          winLength = len; 
          winStart = left; 
      } 
    }
  }
  return strN.substr(winStart, winLength);
}

/******************************************************************************* 
// Solution using unordered_map
#include <unordered_map>
string MinWindowSubstring(string strArr[], int arrLength) {
  string strN = strArr[0]; unordered_map<char, int> hashMapN;
  string strK = strArr[1]; unordered_map<char, int> hashMapK;
  
  // Store the occurrences of characters of string K
  for (int i = 0; i < strK.length(); i++)
    ++hashMapK[strK[i]];

  int left = 0, winStart = 0, winLength = strN.length() + 1;
  int count = 0;

  // Traverse the N string 
  for (int right = 0; right < strN.length(); right++) {
    ++hashMapN[strN[right]];
    if (hashMapK.count(strN[right]) != 0 && hashMapN[strN[right]] <= hashMapK[strN[right]])
      count++;

    // If all string K characters are accounted for in the current string N substring
    if (count == strK.length()) {
      // Try to minimize the window i.e., check if any character is occurring more no. of times than its occurrence in pattern, 
      // if yes then remove it from starting and also remove the useless characters. 
      while (hashMapK.count(strN[left]) == 0 || hashMapN[strN[left]] > hashMapK[strN[left]])
      { 
          if (hashMapK.count(strN[left]) != 0 && hashMapN[strN[left]] > hashMapK[strN[left]]) 
              --hashMapN[strN[left]];
          left++; 
      } 

      // update window size 
      int len = right - left + 1; 
      if (winLength > len) 
      { 
          winLength = len; 
          winStart = left; 
      } 
    }
  }
  return strN.substr(winStart, winLength);
}
********************************************************************************/

/******************************************************************************* 
// Solution using arrays of 256 characters
string MinWindowSubstring(string strArr[], int arrLength) {
  string strN = strArr[0]; int lenN = strArr[0].length();
  string strK = strArr[1]; int lenK = strArr[1].length();

  int hashArrayN[256] = {0}; 
  int hashArrayK[256] = {0}; 

  // store occurrences of characters of string K
  for (int i = 0; i < lenK; i++) 
    hashArrayK[strK[i]]++; 

  int left = 0, winStart = 0, winLength = lenN + 1; 

  // start traversing the N string 
  int count = 0; // count of characters 
  for (int right = 0; right < lenN ; right++) 
  { 
    hashArrayN[strN[right]]++;
    if (hashArrayK[strN[right]] != 0 && hashArrayN[strN[right]] <= hashArrayK[strN[right]])
      count++; 

    // if all the characters are matched 
    if (count == lenK) 
    { 
      // Try to minimize the window i.e., check if any character is occurring more no. of times than its occurrence in pattern, 
      // if yes then remove it from starting and also remove the useless characters. 
      while (hashArrayK[strN[left]] == 0 || hashArrayN[strN[left]] > hashArrayK[strN[left]]) 
      { 
        if (hashArrayN[strN[left]] > hashArrayK[strN[left]]) 
          hashArrayN[strN[left]]--; 
        left++; 
      } 

      // update window size 
      int len = right - left + 1; 
      if (winLength > len) 
      { 
        winLength = len; 
        winStart = left; 
      } 
    } 
  } 
  return strN.substr(winStart, winLength);
}
********************************************************************************/

int main(void) { 
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << MinWindowSubstring(A, arrLength);
  return 0;
}
