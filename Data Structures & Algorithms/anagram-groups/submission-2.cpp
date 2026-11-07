class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> data;
        for(auto s : strs){
            auto sorted = s;
            sort(sorted.begin(), sorted.end());
            data[sorted].push_back(s);
        }
        vector<vector<string>> res;
        for(const auto& k : data) {
            res.push_back(data[k.first]);
        }
        return res;
    }
};
