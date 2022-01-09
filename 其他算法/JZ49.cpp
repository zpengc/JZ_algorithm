class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<=6)
            return index;
        vector<int> arr(index);
        arr[0] = 1;
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        for(int i=1;i<index;i++)  {
            arr[i] = min(int(arr[i2]*2), min(int(arr[i3]*3), int(arr[i5]*5)));
            if(arr[i] == arr[i2]*2) 
                i2++;
            if(arr[i] == arr[i3]*3) 
                i3++;
            if(arr[i] == arr[i5]*5)
                i5++;
        }
        return arr[index-1];
    }
};