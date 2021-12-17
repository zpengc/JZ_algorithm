class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return int整型
     */
    int StrToInt(string s) {
        // write code here
        int ans = 0;
        int positive = 1;
        int head = 0, tail = s.size()-1;
        while(head<s.size() && s[head]==' ')
            head++;
        while(tail>=0 && s[tail]==' ')
            tail--;
        if(s[head]=='-')
        {
            head++;
            positive = -1;
        }
        else if(s[head]=='+')
        {
            head++;
            positive = 1;
        }
        while(head<=tail)
        {
            if('0'<=s[head] && s[head]<='9')
            {
                ans = ans*10 + (s[head]-'0');
                if(ans<0)
                {
                    if(positive==1)
                        return INT_MAX;
                    else
                        return INT_MIN;
                }
                head++;
            }
            else
                break;
        }
        return ans*positive;
    }
};