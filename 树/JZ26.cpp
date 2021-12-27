class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(pRoot1 == NULL || pRoot2 == NULL)
            return false;
        if(helper(pRoot1, pRoot2))
            return true;
        if(HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2))
            return true;
        return false;
    }
    
    bool helper(TreeNode* n1, TreeNode* n2)
    {
        bool left = true;
        bool right = true;
        if(n1==NULL || n1->val!=n2->val)
            return false;
        if(n2->left)
            left = helper(n1->left, n2->left);
        if(n2->right)
            right = helper(n1->right, n2->right);
        return left&&right;
    }
};