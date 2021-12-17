class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int up = 0, down = matrix.size()-1;
        int left = 0, right = matrix[0].size()-1;
        vector<int> ans;
        while(up < down && left<right)
        {
            for(int j=left;j<=right;j++)
            {
                ans.push_back(matrix[up][j]);
            }
            for(int i=up+1;i<=down;i++)
            {
                ans.push_back(matrix[i][right]);
            }
            for(int j=right-1;j>=left;j--)
            {
                ans.push_back(matrix[down][j]);
            }
            for(int i=down-1;i>=up+1;i--)
            {
                ans.push_back(matrix[i][left]);
            }
            up++;
            down--;
            left++;
            right--;
        }
        if(up==down)
        {
            for(int j=left;j<=right;j++)
            {
                ans.push_back(matrix[up][j]);
            }
            return ans;
        }
        if(left==right)
        {
            for(int i=up;i<=down;i++)
            {
                ans.push_back(matrix[i][left]);
            }
            return ans;
        }
        return ans;
    }
};