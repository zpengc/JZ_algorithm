int InversePairs(vector<int> data) {
        int ans;
        mergeSort(data, 0, data.size()-1, ans);
        return ans%1000000007;
    }
    
    void mergeSort(vector<int>& data, int low, int high, int& ans)
    {
        if(low>=high)
            return;
        int middle = (low+high)/2;
        mergeSort(data, low, middle, ans);
        mergeSort(data, middle+1, high, ans);
        merge(data, low, middle, high, ans);
    }
    
    void merge(vector<int>& data, int low, int middle, int high, int& ans)
    {
        vector<int> tmp(high-low+1);
        int i = low, j = middle+1, k = 0;
        while(i<=middle && j<=high)
        {
            if(data[i]>data[j]) // 逆序对
            {
                tmp[k++] = data[j++];
                ans += (middle-i+1); // i元素比后面大，则i+1，i+2，一直到middle元素都比后面大，因为子序列已经排好序了
                ans = ans%1000000007;
            }
            else
            {
                tmp[k++] = data[i++];
            }
        }
        while(i<=middle)
        {
            tmp[k++] = data[i++];
        }
        while(j<=high)
        {
            tmp[k++] = data[j++];
        }
        k = 0;
        i = low;
        for(;i<=high;i++,k++)
        {
            data[i] = tmp[k];
        }
    }