class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if(pRoot==NULL)
            return true;
        return helper(pRoot->left, pRoot->right);
    }
    
    bool helper(TreeNode* n1, TreeNode* n2) {
        if(n1==NULL && n2==NULL) {
            return true;
        }
        if(n1==NULL || n2==NULL) {
            return false;
        }
        if(n1->val==n2->val) {
            return helper(n1->left, n2->right) && helper(n1->right, n2->left);
        }
        return false;
    }
};