class Solution {
public:
    int cutRope(int number) {
        if(number==2 || number==3)
            return number-1;
        int ans = 1;
        while(number>4) {
           number -= 3;
            ans *= 3;
        }
        return ans * number;
        
    }
};