class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        // write code here
        vector<int> ans;
        int sum = 0;
        int maxi = array[0];
        int end_idx = 0;
        int begin_idx = 0;
        for(int i=0;i<array.size();i++)
        {
            if(sum+array[i]<0)
                sum = 0;
            else
            {
                sum += array[i];
                if( sum >= maxi)
                {
                    maxi = sum;
                    end_idx = i;
                }
            }
        }
        if(maxi<0)
        {
            int ans = array[0];
            for(int i=1;i<array.size();i++)
            {
                if(ans<array[i])
                    ans = array[i];
            }
            return {ans};
        }
        for(int i=end_idx;i>=0;i--)
        {
            maxi -= array[i];
            if(maxi==0)
                begin_idx = i;
        }
        for(int i=begin_idx;i<=end_idx;i++)
        {
            ans.push_back(array[i]);
        }
        return ans;
    }
};