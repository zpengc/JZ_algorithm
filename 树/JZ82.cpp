class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode* root, int sum) {
        // write code here
        if(root==NULL)
            return false;
        return helper(root, sum);
    }
    
    bool helper(TreeNode* node, int sum)
    {
        if(node->left==NULL && node->right==NULL)
            return node->val == sum;
        bool left = false;
        bool right = false;
        if(node->left)
            left = helper(node->left, sum-node->val);
        if(node->right)
            right = helper(node->right, sum-node->val);
        return left || right;
    }
};