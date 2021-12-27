class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> qq;
        qq.push(root);
        while(!qq.empty())
        {
            int size = qq.size();
            TreeNode* temp = qq.front();
            ans.push_back(temp->val);
            if(temp->left)
                qq.push(temp->left);
            if(temp->right)
                qq.push(temp->right);
            qq.pop();
        }
        return ans;
    }
};