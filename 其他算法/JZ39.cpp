class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int ans = numbers[0];
        int count =  1;
        for(int i=1;i<numbers.size();i++) {
            if(numbers[i]==ans)
                count++;
            else {
                count--;
                if(count<=0) {
                    ans = numbers[i+1];
                    count = 1;
                }
            }
        }
        
        return ans;
    }
    
    
};