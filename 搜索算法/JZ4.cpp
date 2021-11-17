class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = 0;
        int col = array[0].size()-1;
        while(row<=array.size()-1 && col>=0)
        {
            if(target == array[row][col])
                return true;
            else if(target < array[row][col])
                col--;
            else
                row++;
        }
        return false;
    }
};