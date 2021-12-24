class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> ans;
        if(pRoot==NULL)
            return ans;
        int flag = 1;  // 1代表从左往右，0代表从右往左
        queue<TreeNode*> qq;
        qq.push(pRoot);
        while(!qq.empty())
        {
            vector<int> temp;
            int size = qq.size();
            while(size--)
            {
                TreeNode* node = qq.front();
                qq.pop();
                temp.push_back(node->val);
                if(node->left)
                    qq.push(node->left);
                if(node->right)
                    qq.push(node->right);
            }
            if(flag==0)
                reverse(temp.begin(), temp.end());
            flag = flag ^ 1;
            ans.push_back(temp);
        }
        return ans;
    }
    
};