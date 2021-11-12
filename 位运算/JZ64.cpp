class Solution {
public:
    int Sum_Solution(int n) {
        // &&运算符，如果左边条件成立，执行右边条件，如果左侧条件不成立，直接返回False，不执行右边条件
        bool x = n>1 && (n += Sum_Solution(n-1));
        return n;
    }
};