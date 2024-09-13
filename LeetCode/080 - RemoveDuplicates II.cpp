/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the 80. Remove Duplicates from Sorted Array II from Leetcode:
//              https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int N = static_cast<int>(nums.size());
        int k = min(2, N);
        for (int i = 2; i < N; ++i) {
            if (nums[i] != nums[k - 2]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};