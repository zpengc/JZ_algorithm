class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num,  unsigned int size) {
        if(size==0 || size>num.size())
            return {};
        vector<int> ans;
        deque<int> qq;
        for(int i=0;i<num.size();i++)
        {
            if(!qq.empty() && qq.front()==i-(int)size)
                qq.pop_front();  // 超出滑动窗口范围，弹出
            while(!qq.empty() && num[qq.back()]<num[i]) // 始终保持front位置是窗口内最大值
                qq.pop_back();  
            qq.push_back(i);  
            if(i-(int)size+1>=0)
            {
                ans.push_back(num[qq.front()]);  // 窗口右边界
            }
        }
        return ans;
    }
};