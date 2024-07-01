class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int N = static_cast<int>(nums.size());
        int k = min(1, N);

        for (int i = 1; i < N; ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[k++] = nums[i];
            }
        }
        return k;
        
    }
};

// Actually erasing the duplicates in nums matching val and resizing nums (0ms)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int N = static_cast<int>(nums.size());

        for (int i = N - 1; i >= 1; --i) {
            if (nums[i] == nums[i - 1]) {
                nums.erase(nums.begin() + i);
            }
        }
        return nums.size();
        
    }
};

