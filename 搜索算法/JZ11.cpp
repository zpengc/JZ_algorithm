class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int low = 0;
        int high = rotateArray.size()-1;
        while(low<high)
        {
            int middle = (low+high)/2;
            if(rotateArray[middle] == rotateArray[high])
                high--;
            else if(rotateArray[middle] > rotateArray[high])
                low = middle+1;
            else
                high = middle;
                
        }
        return rotateArray[high];
    }
};