class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.size()==0)
            return "";
        if(n<=str.size()) {
            return str.substr(n) + str.substr(0, n);
        }
        else {
            n %= str.size();
            return str.substr(n) + str.substr(0, n);
        }
    }
};