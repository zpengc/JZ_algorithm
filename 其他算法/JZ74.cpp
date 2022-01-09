class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> ans;
        int low = 1;
        int high = 1;
        int temp = 0;
        while(low <= sum/2) {
            if(temp<sum) {
                temp += high;
                high++;
            }
            else if(temp>sum) {
                temp -= low;
                low++;
            }
            else {
                vector<int> vv;
                for(int i=low;i<high;i++) {
                    vv.push_back(i);
                }
                ans.push_back(vv);
                temp -= low;
                low++;
            }
        }
        return ans;
    }
};