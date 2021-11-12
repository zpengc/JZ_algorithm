class Solution {
public:
    double Power(double base, int exponent) {
        if(base==0)
            return 0;
        if(exponent==0)
            return 1;
        if(exponent<0)
        {
            exponent = -exponent;
            base = 1/base;
        }
        double ans = 1.0;
        // 从最低位开始遍历exponent二进制的每一位
        while(exponent)
        {
            // 如果最低位是1
            if(exponent & 1)
            {
                ans *= base;
            }
            // 依次是base^1,base^2,base^4,base^8...
            base = base * base;
            // 右移位，舍弃最低位
            exponent = exponent>>1;
        }
        return ans;
    }
};