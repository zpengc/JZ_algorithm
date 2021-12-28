class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==NULL)
            return true;
        int ans = true;
        helper(pRoot, ans);
        return ans;
    }
    
    int helper(TreeNode* node, int& ans)
    {
        if(node->left==NULL && node->right==NULL)
            return 1;
        int left = 0;
        int right = 0;
        if(node->left)
            left = helper(node->left, ans);
        if(node->right)
            right = helper(node->right, ans);
        if( abs(left-right) > 1)
            ans = false;
        return max(left, right)+1;
    }
};