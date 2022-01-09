class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        // write code here
        int odd = 0;
        for(int i=0;i<array.size();i++) {
            if(array[i]%2!=0) {
                int temp = array[i];
                for(int k=i-1;k>=odd;k--) {
                    array[k+1] = array[k];
                }
                array[odd] = temp;
                odd++;
            }
        }
        return array;
    }
};