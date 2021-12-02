class Solution {
public:
    vector<string> Permutation(string str) {
        if(str=="")
            return {};
        set<string> ans;
        helper(0, str, ans);
        return vector<string>({ans.begin(), ans.end()});
    }
    
    void helper(int pos, string str, set<string>& ans)
    {
        if(pos==str.size()-1)
        {
            ans.insert(str);
            return;
        }
        for(int i=pos;i<str.size();i++)
        {
            swap(str[i], str[pos]);
            helper(pos+1, str, ans);
            swap(str[i], str[pos]);
        }
    }
};