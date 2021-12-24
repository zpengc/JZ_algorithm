class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0 || vin.size()==0)
            return NULL;
        return helper(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
    }
    
    TreeNode* helper(vector<int> pre, int pre_start, int pre_end, vector<int> vin, int vin_start, int vin_end)
    {
        if(pre_start > pre_end)
            return NULL;
        TreeNode* head = new TreeNode(pre[pre_start]);  // 根节点
        if(pre_start == pre_end)
            return head;
        int middle = vin_start;
        for(;middle<=vin_end;middle++)
        {
            if(pre[pre_start] == vin[middle])
                break;
        }
        // 切割中序序列，分成左右两部分
        int vin_left_start = vin_start;
        int vin_left_end = middle - 1;
        
        int vin_right_start = middle + 1;
        int vin_right_end = vin_end;
        
        // 切割前序序列，分成左右两部分，不包括根节点
        int pre_left_start = pre_start + 1;
        int pre_left_end = pre_start + 1 + vin_left_end - vin_left_start;
        
        int pre_right_start = pre_left_end + 1;
        int pre_right_end = pre_end;
        
        // 递归
        head->left = helper(pre, pre_left_start, pre_left_end, vin, vin_left_start, vin_left_end);
        head->right = helper(pre, pre_right_start, pre_right_end, vin, vin_right_start, vin_right_end);
        return head;
    }
};