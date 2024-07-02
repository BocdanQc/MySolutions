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