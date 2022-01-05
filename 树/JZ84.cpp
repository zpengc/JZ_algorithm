class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return int整型
     */
    int FindPath(TreeNode* root, int sum) {
        // write code here
        if(root==NULL)
            return 0;
        return FindPath(root->left, sum) + FindPath(root->right, sum) + helper(root, sum);
    }
    
    int helper(TreeNode* node, int sum) {
        int count = 0;
        if(node==NULL) 
            return 0;
        if(node->val==sum)
            count++;
        return helper(node->left, sum-node->val) + helper(node->right, sum-node->val) + count;
    }
    
    
    
    
};