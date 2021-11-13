class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        if(pHead==0)
            return NULL;
        ListNode* slow = pHead;
        ListNode* fast = pHead;
        int length = 0;
        while(fast)
        {
            length++;
            fast = fast->next;
        }
        if(length<k)
            return NULL;
        fast = pHead;
        for(int i=0;i<k;i++)
        {
            fast = fast->next;
        }
        while(fast && slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};