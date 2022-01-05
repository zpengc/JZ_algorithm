class Solution {
public:
    char* Serialize(TreeNode *root) {    
        if(root==NULL) {
            return NULL;
        }

        string str="";
        queue<TreeNode*> qq;
        qq.push(root);
        while(!qq.empty()) {
            TreeNode* temp = qq.front();
            qq.pop();
            if(temp==NULL) {
                str += "#";
                str += ",";
                continue;
            }
            str += to_string(temp->val);
            str += ",";
            qq.push(temp->left);
            qq.push(temp->right);
        }
        char *ans = new char[str.length() + 1];
        strcpy(ans, str.c_str());
        return ans;
    }
    
    TreeNode* Deserialize(char *str) {
        if(str==NULL)
            return NULL;
        if(str[0]=='#')
            return NULL;
        int idx = 1;
        string s(str);
        
        queue<TreeNode*> qq;
        TreeNode* head = new TreeNode(atoi(str));
        qq.push(head);
        s = s.substr(s.find_first_of(',')+1);
        while(!s.empty() && !qq.empty()) {
            TreeNode* temp = qq.front();
            qq.pop();
            if(s[0]=='#') {
                temp->left = NULL;
                s = s.substr(2);
                
            }
            else {
                temp->left = new TreeNode(atoi(s.c_str()));
                qq.push(temp->left);
                s = s.substr(s.find_first_of(',') + 1);
            }
            if(s[0]=='#') {
                temp->right = NULL;
                s = s.substr(2);
                
            }
            else {
                temp->right = new TreeNode(atoi(s.c_str()));
                qq.push(temp->right);
                s = s.substr(s.find_first_of(',') + 1);
            }
        }
        return head;
        
    }
};