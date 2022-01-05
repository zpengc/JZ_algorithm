class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        return helper(root, o1, o2)->val;
    }
    
    TreeNode* helper(TreeNode* node, int o1, int o2) {
        if(node==NULL || node->val==o1 || node->val==o2)
            return node;
        TreeNode* left = helper(node->left, o1, o2);
        TreeNode* right = helper(node->right, o1, o2);
        if(left==NULL) 
            return right;
        if(right==NULL)
            return left;
        return node;
    }
};