class Solution {
public:
    // https://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators/
    int Add(int num1, int num2) {
        if(num1==0)
        {
            return num2;
        }
        if(num2==0)
        {
            return num1;
        }
        // https://en.wikipedia.org/wiki/Adder_%28electronics%29#Half_adder
        // 半加器的思想，对1 bit加法而言，进位是与&，和是异或^
        while(num2)
        {
            int carry = num1 & num2;
            num1 = num1 ^ num2;
            num2 = carry << 1;
        }
        return num1;
    }
};