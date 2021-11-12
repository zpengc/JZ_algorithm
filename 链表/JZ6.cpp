class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        // 保存结果
        vector<int> ans;
        if(head==NULL)
        {
            return ans;
        }
        helper(head, ans);
        return ans;
    }
    
    // 递归思路，不断深入到链表尾部节点，然后递归返回的时候获取节点信息
    void helper(ListNode* node, vector<int>& v)
    {
        if(node)
        {
            helper(node->next, v);
            v.push_back(node->val);
        }
    }
};