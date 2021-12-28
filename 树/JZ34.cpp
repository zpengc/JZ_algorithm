class Solution {
public:
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        vector<int> temp;
        helper(root, expectNumber, temp, ans);
        return ans;
    }
    
    void helper(TreeNode* node, int sum, vector<int>& temp, vector<vector<int>>& ans)
    {
        temp.push_back(node->val);
        if(node->left==NULL && node->right==NULL)
        {
            if(node->val == sum)
            {
                ans.push_back(temp);
            }
        }
        if(node->left)
            helper(node->left, sum-node->val, temp, ans);
        if(node->right)
            helper(node->right, sum-node->val, temp, ans);
        temp.pop_back();
    }
};