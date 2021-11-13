class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        ListNode* curr = pHead;
        ListNode* pre = NULL;
        while(curr)
        {
            ListNode* temp = curr->next;
            if(temp==NULL)
                return pHead;
            if(temp->val!=curr->val)
            {
                pre = curr;
                curr = curr->next;
            }
            else
            {
                while(temp && temp->val==curr->val)
                {
                    temp = temp->next;
                }
                if(pre)
                {
                    pre->next = temp; 
                    curr = temp;
                }
                else if(temp==NULL)
                    return NULL;
                else
                {
                    pHead = temp;
                    return deleteDuplication(pHead);
                }
            }
        }
        return pHead;
    }
};