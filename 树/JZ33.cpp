class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()==0)
            return false;
        return helper(sequence, 0, sequence.size()-1);
    }
    
    bool helper(vector<int>& sequence, int low, int high)
    {
        if(low>=high)
            return true;
        int middle = sequence[high];
        int i;
        for(i=low;i<sequence.size() && sequence[i]<middle;i++);
        for(int j=low;j<=i-1;j++)
        {
            if(middle<sequence[j])
                return false;
        }
        for(int j=i;j<=high-1;j++)
        {
            if(middle>sequence[j])
                return false;
        }
        return helper(sequence, low, i-1) && helper(sequence, i, high-1);
    }
};