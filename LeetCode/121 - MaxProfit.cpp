/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author: Daniel Emond
//
// Description: My C++ solution to the 121. Best Time to Buy and Sell Stock from Leetcode:
//              https://leetcode.com/problems/best-time-to-buy-and-sell-stock
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = static_cast<int>(prices.size());
        int buy = (N > 0 ? prices[0] : 0);
        int profit = 0;
        for (int i = 1; i < N; i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else if (prices[i] - buy > profit) {
                profit = prices[i] - buy;
            }
        }
        return profit;
    }
};