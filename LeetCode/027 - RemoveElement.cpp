// Sliding the elements in nums to remove val (0ms)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        const int N = static_cast<int>(nums.size());
        int k = 0;

        for (int i = 0; i < N; ++i) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};

// Actually erasing the elements in nums matching val and resizing nums (0ms)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        const int N = static_cast<int>(nums.size());

        for (int i = N - 1; i >= 0; --i) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
            }
        }
        return nums.size();
    }
};

// Using vector copy, looping on iterators (2ms)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> temp;
        for (auto ite = nums.begin(); ite != nums.end(); ++ite) {
            if (*ite != val) {
                temp.push_back(*ite);
            }
        }
        nums = temp;
        return nums.size();
    }
};

// Using vector copy, looping on index (2ms)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        const int N = static_cast<int>(nums.size());
        vector<int> temp;
        for (int i = 0; i < N; ++i) {
            if (nums[i] != val) {
                temp.push_back(nums[i]);
            }
        }
        nums = temp;
        return nums.size();
    }
};

