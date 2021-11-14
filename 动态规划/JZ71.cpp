class Solution {
public:
    // 找规律题目
    // f(1) = 1, f(2) = 2, f(3) = 8, f(4) = 16
    int jumpFloorII(int number) {
        return (1<<(number-1));
    }
};