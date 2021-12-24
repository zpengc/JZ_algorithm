class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        if(pRoot==NULL)
            return 0;
        return helper(pRoot, 1);
    }
    
    int helper(TreeNode* p, int depth)
    {
        if(p==NULL)
            return depth-1;
        return max(helper(p->left, depth+1), helper(p->right, depth+1));
    }
    
};