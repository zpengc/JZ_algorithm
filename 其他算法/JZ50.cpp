class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> mm;
        for(int i=0;i<str.size();i++) {
            mm[str[i]]++;
        }
        
        for(int i=0;i<str.size();i++) {
            if(mm[str[i]]==1)
                return i;
        }
        return -1;
    }
};