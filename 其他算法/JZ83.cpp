class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param number long长整型 
     * @return long长整型
     */
    long long cutRope(long long number) {
        // write code here
        if(number==2 || number==3)
            return number-1;
        if(number%3==0)
            return helper(number/3) % 998244353 ;
        else if(number%3==1)
            return helper(number/3-1) * 4 % 998244353 ;
        else 
            return helper(number/3) * 2 % 998244353 ;
    }
    
    long long helper(long long power) {
        if(power==0)
            return 1;
        if(power==1)
            return 3;
        long long half = helper(power/2);
        if(power%2==0)
            return half * half % 998244353 ;
        else 
            return 3 * half * half % 998244353 ;
    }
};