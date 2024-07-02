#include <unordered_map>

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        const int N = static_cast<int>(nums.size());
        const int MAJORITY = N >> 1;

        int majority = (N > 0 ? nums[0] : 0);

        unordered_map<int, int> counts;

        for (int i = 0; i < N; ++i) {
            ++counts[nums[i]];
        }

        for (auto &c : counts) {
            //if (c.second > counts[majority]) {
            //    majority = c.first;
            //    if (counts[majority] > MAJORITY) {
            //        break;
            //    }
            if (c.second > MAJORITY) {
                majority = c.first;
                break;
            }
        }

        return majority;
    }
};