class Solution {
public:
    int jump(vector<int>& nums) {
        const int MAX_IDX = nums.size() - 1;
	    int idx = 0, jumps = 0, maxIdx = 0, lastIdx = 0;

        while (lastIdx < MAX_IDX) {
		    maxIdx = max(maxIdx, idx + nums[idx]);
            if (idx == lastIdx) {
    			lastIdx = maxIdx;
    			jumps++;
	    	}            
		    idx++;
	    }
	    return jumps;
    }
};