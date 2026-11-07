class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> data;
        for (const string& s : strs) {
            string sorted_str = s;
            std::sort(sorted_str.begin(), sorted_str.end());
    
            // Grouping by the sorted key
            data[sorted_str].push_back(s); 
        }
        // 2. Move the grouped vectors from the map into the required return format
        vector<vector<string>> result;
        for (const auto& pair : data) {
            result.push_back(pair.second); // pair.second is the vector<string>
        }
        
        return result;
    }
};
