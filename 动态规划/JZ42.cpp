class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int dp[array.size()];
        dp[0] = array[0];
        for(int i=1;i<array.size();i++)
        {
            dp[i] = max(array[i], dp[i-1]+array[i]);
        }
        int ans = INT_MIN;
        for(int i=0;i<array.size();i++)
        {
            if(ans < dp[i])
            {
                ans = dp[i];
            }
        }
        return ans;
    }
};