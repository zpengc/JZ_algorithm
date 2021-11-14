class Solution {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
   
    int helper(string s, int dp[], int idx)
    {
        if(idx>=s.size())
            return 1;
        if(idx<s.size() && s[idx]=='0')
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        if(s[idx]!='0')
        {
            dp[idx] = helper(s, dp, idx+1);
        }
        if( idx+1<s.size() && ((s[idx]=='1' && s[idx+1]<='9') || (s[idx]=='2' && s[idx+1]<='6')))
            dp[idx] += helper(s, dp, idx+2);
        return dp[idx];
    }
    
    int solve(string s) {
        int dp[s.size()];
        memset(dp, -1, sizeof(dp));
        return helper(s, dp, 0);
    }
       
};