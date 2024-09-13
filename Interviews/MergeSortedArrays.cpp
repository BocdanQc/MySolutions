/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution a problem from an interview on Leetcode (https://leetcode.com/) where I had to merge 2 sorted
//              arrays. It is similar to the [88] MergedSortedArray problem also from Leetcode
//              (see https://leetcode.com/problems/merge-sorted-array/description/)
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<int> mergeSortedArrays(const std::vector<int> &arr1, const std::vector<int> &arr2) {
    std::vector<int> merged;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i++]);
        } else {
            merged.push_back(arr2[j++]);
        }
    }
    while (i < arr1.size()) {
        merged.push_back(arr1[i++]);
    }
    while (j < arr2.size()) {
        merged.push_back(arr2[j++]);
    }
    return merged;
}