class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @param val int整型 
     * @return ListNode类
     */
    ListNode* deleteNode(ListNode* head, int val) {
        // write code here
        if(head==NULL)
            return NULL;
        if(head->val==val)
            return head->next;
        ListNode* pre = head;
        ListNode* curr = head->next;
        while(curr)
        {
            if(curr->val!=val)
            {
                pre = curr;
                curr = curr->next;
            }
            else
            {
                pre->next = curr->next;
                return head;
            }
        }
        return head;
    }
};