class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int N = nums.size();
        int nextIdx = (N > 0 ? nums[0] : 0);
        for (int i = 0; i < N; ++i) {
            if (nextIdx >= N - 1)
                return true;
            else if (nums[i] == 0 && nextIdx == i)
                return false;
            else if (i + nums[i] > nextIdx) {
                nextIdx = i + nums[i];
            }
        }
        return true;
    }
};