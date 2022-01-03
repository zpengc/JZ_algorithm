class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(pNode==NULL)
            return NULL;
        if(pNode->right) {
            pNode = pNode->right;
            while(pNode->left) {
                pNode = pNode->left;
            }
            return pNode;
        }
        
        while(pNode->next) {
            TreeLinkNode* parent = pNode->next;
            if(parent->left == pNode) {
                return parent;
            }
            pNode = pNode->next;
        }
        
        return NULL;
    }
    
    
};