class Solution {
private:
    stack<int> ss;
    stack<int> tmp;
public:
    void push(int value) {
        ss.push(value);
    }
    void pop() {
        ss.pop();
    }
    int top() {
        return ss.top();
    }
    int min() {
        int ans = INT_MAX;
        while(!ss.empty())
        {
            int ele = ss.top();
            if(ele<ans)
            {
                ans = ele;
            }
            tmp.push(ele);
            ss.pop();
        }
        while(!tmp.empty())
        {
            ss.push(tmp.top());
            tmp.pop();
        }
        return ans;
    }
};