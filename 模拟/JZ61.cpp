class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        sort(numbers.begin(), numbers.end());
        int zero_num = 0;
        for(int i=0;i<numbers.size();i++)
        {
            if(numbers[i]==0)
                zero_num++;
            else
                break;
        }
        int distance = 0;
        for(int i=zero_num;i<numbers.size()-1;i++)
        {
            if(numbers[i]==numbers[i+1])
                return false;
            distance += numbers[i+1] - numbers[i] - 1;
        }
        if(zero_num>=distance)
            return true;
        return false;
    }
};