class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if(pRootOfTree==NULL)
            return NULL;
        TreeNode* start = pRootOfTree;
        while(start->left)
        {
            start = start->left;
        }
        helper(pRootOfTree, 0, 0);
        return start;
    }
    
    TreeNode* helper(TreeNode* node, int l, int r)
    {
        if(node->left==NULL && node->right==NULL)
            return node;
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        if(node->left)
        {
            left = helper(node->left, 1, 0);
            left->right = node;
            node->left = left;
        }
        if(node->right)
        {
            right = helper(node->right, 0, 1);
            right->left = node;
            node->right = right;
        }
        if(l==1)
        {
            if(right==NULL)
                return node;
            return right;
        }
        else
        {
            if(left==NULL)
                return node;
            return left;
        }
    }
};