class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param grid int整型vector<vector<>> 
     * @return int整型
     */
    int maxValue(vector<vector<int> >& grid) {
        // write code here
        int n_row = grid.size();
        int n_col = grid[0].size();
        int dp[n_row][n_col];
        for(int i=0;i<n_row;i++)
        {
            for(int j=0;j<n_col;j++)
            {
                dp[i][j] = grid[i][j];
            }
        }
        for(int i=0;i<n_row;i++)
        {
            for(int j=0;j<n_col;j++)
            {
                if(i==0 && j==0)
                    continue;
                else if(i==0)
                    dp[i][j] += dp[i][j-1];
                else if(j==0)
                    dp[i][j] += dp[i-1][j];
                else
                    dp[i][j] = dp[i][j] + max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n_row-1][n_col-1];
    }
};