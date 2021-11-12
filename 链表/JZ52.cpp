class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==NULL || pHead2==NULL)
            return NULL;
        ListNode* p = pHead1;
        ListNode* q = pHead2;
        int len_1 = 0;
        int len_2 = 0;
        // 统计长度
        while(p)
        {
            len_1++;
            p = p->next;
        }
        while(q)
        {
            len_2++;
            q = q->next;
        }
        // p指向短链表，q指向长链表
        if(len_1<len_2)
        {
            p = pHead1;
            q = pHead2;
        }
        else
        {
            p = pHead2;
            q = pHead1;
        }
        // 长度对齐，让长链表q先走多余的距离
        for(int i=0;i<abs(len_1-len_2);i++)
        {
            q = q->next;
        }
        // 距离相同，一起向后遍历
        while(p && q)
        {
            if(p==q)
                return p;
            p = p->next;
            q = q->next;
        }
        return NULL;
    }
};