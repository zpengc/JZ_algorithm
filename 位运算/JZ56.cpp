class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        vector<int> ans;
        int temp = 0;
        // 假设a和b是最终的两个值，temp就等于a和b的异或结果
        for(int i=0;i<array.size();i++)
        {
            temp = temp ^ array[i];
        }
        int bit = 1;
        // temp&bit少了个括号，导致结果错误，关系运算符优先级大于位运算符
        // 因为异或中不同位才返回1，所以根据temp获得a、b最低的不同位
        while( (temp&bit)==0)
        {
            bit = bit<<1;
        }
        int smaller = 0;
        int bigger = 0;
        // 根据bit将数组元素划分成两类，必将a和b分开
        for(int i=0;i<array.size();i++)
        {
            if(array[i]&bit)
                smaller = smaller ^ array[i];
            else
                bigger = bigger ^ array[i];
        }
        if(smaller>bigger)
        {
            int back = smaller;
            smaller = bigger;
            bigger = back;
        }
        ans.push_back(smaller);
        ans.push_back(bigger);
        return ans;
    }
};