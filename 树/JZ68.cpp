class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @param p int整型 
     * @param q int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        // write code here
        return helper(root, p, q)->val;
    }
    
    TreeNode* helper(TreeNode* node, int p, int q) {
        if(node==NULL || node->val==p || node->val==q || (node->val>p && node->val<q) || 
          (node->val<p && node->val>q)) {
            return node;
        }
        if(node->val>p) {
            return helper(node->left, p, q);
        }
        else {
            return helper(node->right, p, q);
        }
    }
};