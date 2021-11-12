class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        // 空链表，直接返回
        if(pHead==NULL)
        {
            return NULL;
        }
        // 双指针法，不断取q指向的节点，插在p指向的节点前面
        ListNode* p = pHead;
        ListNode* q = pHead->next;
        // 头结点要变成尾节点，把next置空
        pHead->next = NULL;
        while(q)
        {
            ListNode* temp = q->next;
            q->next = p;
            p = q;
            q = temp;
        }
        return p;
    }
};