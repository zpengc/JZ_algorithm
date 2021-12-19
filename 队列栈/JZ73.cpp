class Solution {
public:
    string ReverseSentence(string str) {
        stack<string> ss;
        int first = 1;
        int len = 0;
        int i = 0;
        while(str[i]==' ')
            i++;
        int begin = i;
        for(;i<str.size();i++)
        {
            if(i==str.size()-1)
            {
                if(first)
                    ss.push(str.substr(begin, len+1));
                else
                    ss.push(str.substr(begin, len+1) + " ");
            }
            if(str[i]!=' ')
                len++;
            else
            {
                if(first)
                {
                    first = 0;
                    ss.push(str.substr(begin, len));
                }
                else
                    ss.push(str.substr(begin, len) + " ");
                begin = i+1;
                while(begin<str.size() && str[begin]==' ')
                    begin++;
                len = 0;
            }
        }
        string ans = "";
        while(!ss.empty())
        {
            ans += ss.top();
            ss.pop();
        }
        return ans;
    }
};