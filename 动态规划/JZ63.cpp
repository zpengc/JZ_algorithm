class Solution {
public:
    /**
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        // write code here
        int dp[prices.size()];
        dp[0] = 0;
        int min_price = prices[0];
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<min_price)
                min_price = prices[i];
            dp[i] = prices[i] - min_price;
        }
        
        int ans = dp[0];
        for(int i=1;i<prices.size();i++)
        {
            if(ans<dp[i])
            {
                ans = dp[i];
            }
        }
        return ans;
    }
};