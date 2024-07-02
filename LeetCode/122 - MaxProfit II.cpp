class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length=prices.size();
        int p=0;
        int b=0;
        if(length==1)
        {
            return 0;
        }
        for (int i=0; i<length-1; i++)
        {
            if(prices[i]<prices[i+1])
            {
                b=prices[i];
                p+=prices[i+1]-b;
            }

        }
        return p;
    }
};