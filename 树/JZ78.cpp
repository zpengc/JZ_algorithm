class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> ans;
        if(pRoot==NULL)
            return ans;
        queue<TreeNode*> qq;
        qq.push(pRoot);
        while(!qq.empty()) {
            int size=qq.size();
            vector<int> temp;
            while(size>0) {
                TreeNode* node = qq.front();
                qq.pop();
                temp.push_back(node->val);
                if(node->left)
                    qq.push(node->left);
                if(node->right)
                    qq.push(node->right);
                size--;
            }
            ans.push_back(temp);
        }
        return ans;
    }
    
};