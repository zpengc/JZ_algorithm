class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        // 有任意一个链表为空，不用合并直接返回另一个链表
        if(pHead1==NULL)
        {
            return pHead2;
        }
        if(pHead2==NULL)
        {
            return pHead1;
        }
        ListNode* p;
        ListNode* q;
        // temp总是指向p前一个节点
        ListNode* temp = NULL;
        // p指向第一个元素小的链表
        if(pHead1->val < pHead2->val)
        {
            p = pHead1;
            q = pHead2;
        }
        else
        {
            p = pHead2;
            q = pHead1;
        }
        // ans作为结果返回
        ListNode* ans = p;
        // 遍历q指向的链表，不断将q元素插入p链表合适位置
        while(q!=NULL && p!=NULL)
        {
            // q节点大于p节点，p节点后移，继续寻找位置
            if(p!=NULL && q!=NULL && q->val>=p->val)
            {
                temp = p;
                p = p->next;
            }
            // 找到合适位置，q节点插在temp节点和p节点之间位置
            else if(p!=NULL && q!=NULL && q->val<p->val)
            {
                // 先保存q的下一个节点
                ListNode* t = q->next;
                // 插在temp和p之间
                temp->next = q;  
                q->next = p;
                // 后移
                temp = temp->next;
                q = t;
            }
        }
        if(q==NULL)
        {
            return ans;
        }
        if(p==NULL)
        {
            while(q)
            {
                temp->next = q;
                temp = q;
                q = q->next;
            }
        }
        return ans;
    }
};