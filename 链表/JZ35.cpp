class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(pHead==NULL)
            return NULL;
        RandomListNode* curr = pHead;
        // 插入新节点
        while(curr)
        {
            RandomListNode* temp = curr->next;
            curr->next = new RandomListNode(curr->label);
            curr->next->next = temp;
            curr = temp;
        }
        // 设置插入节点的random指针
        curr = pHead;
        while(curr)
        {
            //有的原节点random指针为空
            curr->next->random = curr->random ? curr->random->next : curr->random;
            curr = curr->next->next;
        }
        RandomListNode* ans = pHead->next;
        curr = pHead;
        // 恢复原节点的next指针
        while(curr)
        {
            RandomListNode* temp = curr->next->next;
            curr->next->next = curr->next->next ? curr->next->next->next : curr->next->next;
            curr->next = temp;
            curr = temp;
        }
        return ans;
    }
};