class Solution
{
public:
    map<char, int> mm;
    list<char> qq;
  //Insert one char from stringstream
    void Insert(char ch) {
        mm[ch]++;
        if(mm[ch]==1) 
            qq.push_back(ch);
        else 
            qq.remove(ch);
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        if(qq.empty())
            return '#';
        return qq.front();
    }

};