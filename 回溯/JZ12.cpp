class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix char字符型vector<vector<>> 
     * @param word string字符串 
     * @return bool布尔型
     */
    bool hasPath(vector<vector<char> >& matrix, string word) {
        // write code here
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                bool ans =  helper(matrix, i, j, word, 0);
                if(ans)
                    return true;
            }
        }
        return false;
    }
    
    bool helper(vector<vector<char> >& matrix, int i, int j, string word, int idx)
    {
        if(i >= matrix.size() || i<0 || j >= matrix[0].size() || j<0 || matrix[i][j]!=word[idx])
            return false;
        if(idx==word.size()-1)
            return true;
        char save = matrix[i][j];
        matrix[i][j] = '#';
        bool ans =  helper(matrix, i+1, j, word, idx+1) || 
            helper(matrix, i-1, j, word, idx+1) ||
            helper(matrix, i, j+1, word, idx+1) ||
            helper(matrix, i, j-1, word, idx+1);
        matrix[i][j] = save;
        return ans;
    }
};