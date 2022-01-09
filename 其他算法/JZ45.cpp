class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> str;
        for(int i=0;i<numbers.size();i++) {
            str.push_back(to_string(numbers[i]));
        }
        
        sort(str.begin(), str.end(), [](string a, string b) {
            return a+b<b+a;
        });
        
        string ans = "";
        for(int i=0;i<str.size();i++) {
            ans+=str[i];
        }
        return ans;
    }
};