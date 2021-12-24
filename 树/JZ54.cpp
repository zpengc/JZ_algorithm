class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param proot TreeNode类 
     * @param k int整型 
     * @return int整型
     */
    int KthNode(TreeNode* proot, int k) {
        // write code here
        int ans = -1;
        int idx = 0;
        helper(proot, idx, k, ans);
        return ans;
    }
    
    void helper(TreeNode* node, int& idx, int k, int& ans)
    {
        if(node==NULL)
            return;
        helper(node->left, idx, k, ans);
        idx++;
        if(idx==k)
            ans = node->val;
        helper(node->right, idx, k, ans);
    }
};