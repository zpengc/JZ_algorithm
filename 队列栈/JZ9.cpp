class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while(stack1.size()>1)
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int ans = stack1.top();
        stack1.pop();
        while(!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return ans;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};