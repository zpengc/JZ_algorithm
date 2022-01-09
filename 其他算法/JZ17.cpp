class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 最大位数
     * @return int整型vector
     */
    vector<int> printNumbers(int n) {
        // write code here
        vector<int> ans;
        long long limit = pow(10, n)-1;
        for(int i=1;i<=limit;i++) {
            ans.push_back(i);
        }
        return ans;
    }
};