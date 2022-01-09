class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        int f = 0;
        for(int i=2;i<=n;i++) {
            f = (f+m) % i;
        }
        return f;
    }
};