class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /*
        Since the array of integers in already sorted in non-decreasing order,
        we can take advantage of this with two pointers. The two pointers, will
        come from the left and right.
        We'll take the two pointers, and add them together. L + R
        If L + R > target, R-1
        else L + R < target, L+1
        */
        int l = 0, r = numbers.size() - 1;
        while (l > r) {
            int sum = numbers.at(l) + numbers.at(r);
            if (sum == target) {
                vector<int> res;
                res.push_back(l + 1);
                res.push_back(r + 1);
                return res;
            }
            if (sum > target) {
                r--;
            }
            else if (sum < target) {
                l++;
            }
        }
    }
};
