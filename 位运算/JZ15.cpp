class Solution {
public:
     int  NumberOf1(int n) {
         if(n==0)
         {
             return 0;
         }
         int ans = 1;
         while(n & (n-1))
         {
             n = n & (n-1);
             ans++;
         }
         return ans;
     }
};