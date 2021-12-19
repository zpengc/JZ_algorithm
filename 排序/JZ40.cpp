class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k==0)
            return {};
        vector<int> ans(k);
        for(int i=0;i<k;i++)
        {
            ans[i] = input[i];
        }
        build_heap(ans);
        for(int i=k;i<input.size();i++)
        {
            if(input[i]<ans[0])
            {
                ans[0] = input[i];
                heapify(ans, 0);
            }
        }
        return ans;
    }
    
    void build_heap(vector<int>& ans)
    {
        for(int i=ans.size()/2-1;i>=0;i--)
        {
            heapify(ans, i);
        }
    }
    
    void heapify(vector<int>& ans, int i)
    {
        if(i>= ans.size()/2)
            return;
        int left = i*2+1;
        int right = i*2+2;
        int bigger = ans[left] > ans[i] ? left : i;
        if(right < ans.size())
        {
            bigger = ans[right] > ans[bigger] ? right : bigger;
        }
        if(bigger!=i)
        {
            swap(ans[i], ans[bigger]);
            heapify(ans, bigger);
        }
    }
};