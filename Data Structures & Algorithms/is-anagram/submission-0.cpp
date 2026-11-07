class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }
        map<char,int> data_s;
        map<char,int> data_t;
        for(int i = 0; i < s.length(); i++) {
            data_s[s.at(i)]++;
            data_t[t.at(i)]++;
        }
        return(data_s == data_t);
    }
};
