/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the 188. Rotate Array problem from Leetcode:
//              https://leetcode.com/problems/rotate-array/description/
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int N = static_cast<int>(nums.size());
        if (N > 0 && k > 0) {
            vector<int> numsCopy = nums;
            int nbRots = k % N;
            if (nbRots > 0) {
                for (int i = 0; i < N; ++i) {
                    nums[(i + nbRots) % N] = numsCopy[i];
                }
            }
        }        
    }
};