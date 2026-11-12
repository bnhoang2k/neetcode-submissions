class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> data;
        /*
        Our mindset is to solve with with L, R pointers. We want three numbers that will add
        up to 0. One number must always be picked; so really we're looking for two numbers that
        add up to the "(-)" of that number. E.g., n1 + MIDDLE + n2 where n1 + n2 == "(-)"MIDDLE

        (L <-> M) + (M) + (M <-> R)

        Edge Cases; when the middle is either the first or last element.
        */

        // First sort "nums" otherwise this algorithm won't work.
        sort(nums.begin(), nums.end());

        for(int i = 0 ; i < nums.size(); i++) {
            int l = 0, r = nums.size() - 1;
            int target = -(nums.at(i));
            // First edge case; i == 0
            if (i == 0) {
                l = i + 1;
                r = nums.size() - 1;
            }
            else if (i == nums.size() - 1) {
                l = 0;
                r = i - 1;
            }
            while (l < r) {
                if (l == i) {
                    l++;
                    continue;
                }
                if (r == i) {
                    r--;
                    continue;
                }
                int total = nums.at(l) + nums.at(r);
                if (total == target) {
                    vector<int> res = {nums.at(l), nums.at(i), nums.at(r)};
                    sort(res.begin(), res.end());
                    data.insert(res);
                    l++;
                    r--;
                }
                else if (total < target) {
                    l++;
                }
                else if (total > target) {
                    r--;
                }
            }
        }

        vector<vector<int>> ans(data.begin(), data.end());
        return ans;
    }
};
