class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> pairs;
        for(int i = 0; i < nums.size(); i++) {
            int diff = target - nums.at(i);
            if(pairs.contains(diff)) {
                return vector<int>{pairs[diff], i};
            }
            pairs[nums.at(i)] = i;
            // cout << "Diff: " << diff << " | ";
            // for (auto& [key, val] : pairs) {
            //     cout << "[" << key << " -> " << val << "]";
            // }
            // cout << endl;
        }
        return vector<int>{0, 0};
    }
};
