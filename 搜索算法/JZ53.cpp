class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int ans = 0;
        helper(data, 0, data.size()-1, k, ans);
        return ans;
    }
    
    void helper(vector<int>& data, int low, int high, int k, int& ans)
    {
        if(low>high)
            return;
        while(low <= high)
        {
            int middle = (low+high)/2;
            if(data[middle] == k)
            {
                ans++;
                for(int i=middle-1;i>=low && data[i]==k;i--)
                    ans++;
                for(int i=middle+1;i<=high && data[i]==k;i++)
                    ans++;
                return;
            }
            else if(data[middle] < k)
                low = middle + 1;
            else
                high = middle - 1;
        }
    }
};