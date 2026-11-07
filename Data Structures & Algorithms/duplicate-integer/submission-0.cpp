class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> data;
        for(int i = 0; i < nums.size(); i++) {
            if (data.contains(nums.at(i))) {
                return true;
            }
            data.insert(nums.at(i));
        }
        return false;
    }
};