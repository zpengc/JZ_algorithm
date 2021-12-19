int duplicate(vector<int>& numbers) {
        // write code here
        vector<int> flag(numbers.size(), 0);
        for(int i=0;i<numbers.size();i++)
        {
            flag[numbers[i]]++;
        }
        for(int i=0;i<numbers.size();i++)
        {
            if(flag[i]>1)
            {
                return i;
            }
        }
        return -1;
    }