class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return int整型
     */
    int lengthOfLongestSubstring(string s) {
        // write code here
        int ans = 1;
        int end[256];
        memset(end, -1, sizeof(end));
        
        int idx = 0;
        for(int i=0;i<s.size();i++)
        {
            // 开始坐标
            idx = max(idx, end[s[i]]+1);
            // 存储更大的长度
            ans = max(ans, i-idx+1);
            // 存入新元素
            end[s[i]] = i;
        }
        return ans;
    }
};