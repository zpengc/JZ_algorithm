class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @param pattern string字符串 
     * @return bool布尔型
     */
    // https://redquark.org/leetcode/0010-regular-expression-matching/
    bool match(string str, string pattern) {
        bool dp[str.size()+1][pattern.size()+1];
        // 都是临界条件
        dp[0][0] = true;
        // pattern为空，结果错误
        for(int i=1;i<=str.size();i++)
            dp[i][0] = false;
        // str为空
        for(int j=1;j<=pattern.size();j++)
        {
            if(pattern[j-1]=='*')
                dp[0][j] = dp[0][j-2];
            else 
                dp[0][j] = false;
        }
        // from bottom to up
        for(int i=1;i<=str.size();i++)
        {
            for(int j=1;j<=pattern.size();j++)
            {
                if(pattern[j-1]=='.' || pattern[j-1]==str[i-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(pattern[j-1]=='*')
                {
                    dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (str[i-1] == pattern[j-2] || pattern[j-2] == '.'));
                }
                else
                    dp[i][j] = false;
            }
        }
        return dp[str.size()][pattern.size()];
    }
};