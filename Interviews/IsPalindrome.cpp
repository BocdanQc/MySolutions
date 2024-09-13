/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution a problem from an interview on Leetcode (https://leetcode.com/) where I had to validate if a
//              word is a palidrome. It is similar to the [125] ValidPalidrome problem also from Leetcode
//              (see https://leetcode.com/problems/valid-palindrome/description/)
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool isPalindrome(const std::string &str) {
    int left = 0;
    int right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}