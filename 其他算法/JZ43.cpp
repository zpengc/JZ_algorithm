class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int ans = 0;
        int low = 0;
        int high = n/10;
        int digit = 1;
        int cur = n%10;
        while(cur!=0 || high!=0) {
            if(cur==0) {
                ans += high*digit;
            }
            else if(cur==1) {
                ans += high*digit+low+1;
            }
            else {
                ans += (high+1)*digit;
            }
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return ans;
    }
};


    


