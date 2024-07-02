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