class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> ans;
        int low = 0;
        int high = array.size()-1;
        while(low<high) {
            if(array[low] + array[high] == sum) {
                ans.push_back(array[low]);
                ans.push_back(array[high]);
                return ans;
            }
            else if(array[low] + array[high] < sum) {
                low++;
            }
            else {
                high--;
            }
        }
        return ans;
    }
};