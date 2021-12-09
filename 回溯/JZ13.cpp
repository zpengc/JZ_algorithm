class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        vector<vector<int>> visited(rows, vector<int>(cols));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                visited[i][j] = 1;
            }
        }
        return helper(0, 0, rows, cols, threshold, visited);
    }
    
    
    int helper(int i, int j, int rows, int cols, int threshold, vector<vector<int>>& visited)
    {
        if(i<0 || i>=rows || j<0 || j>=cols || !valid(i,j, threshold)|| visited[i][j]==0)
            return 0;
        visited[i][j] = 0;
        return 1 + helper(i+1, j, rows, cols, threshold, visited) +
        helper(i-1, j, rows, cols, threshold, visited) +
        helper(i, j+1, rows, cols, threshold, visited) +
        helper(i, j-1, rows, cols, threshold, visited);
    }
    
    bool valid(int i, int j, int threshold)
    {
        int ans = 0;
        while(i)
        {
            ans += i%10;
            i = i/10;
        }
        while(j)
        {
            ans += j%10;
            j = j/10;
        }
        return ans<=threshold;
    }
};