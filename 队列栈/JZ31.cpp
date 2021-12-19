class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> ss;
        int push = 0;
        int pop = 0;
        int flag = 0;
        while(pop<=popV.size()-1)
        {
            if(push<pushV.size() && pushV[push]!=popV[pop])
            {
                if(!ss.empty() && popV[pop]==ss.top())
                {
                    ss.pop();
                    pop++;
                }
                else
                {
                    ss.push(pushV[push]);
                    push++;
                }
            }
            else if(push<pushV.size() && pushV[push]==popV[pop])
            {
//                 ss.push(pushV[push]);
//                 ss.pop();
                push++;
                pop++;
            }
            else if(popV[pop]!=ss.top())
            {
                for(int i=push;i<pushV.size();i++)
                {
                    if(pushV[push]==popV[pop])
                        flag = 1;
                }
                if(flag == 0)
                    return false;
            }
            else if(popV[pop]==ss.top())
            {
                ss.pop();
                pop++;
            }
        }
        if(ss.empty())
            return true;
        else
            return false;
    }
};