class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> reOrderArrayTwo(vector<int>& array) {
        // write code here
        int odd = 0;
        int even = array.size()-1;
        while(odd<even) {
            while(array[odd]%2!=0) odd++;
            while(array[even]%2==0) even--;
            if(odd<even)
                swap(array[odd], array[even]);
        }
        return array;
    }
};