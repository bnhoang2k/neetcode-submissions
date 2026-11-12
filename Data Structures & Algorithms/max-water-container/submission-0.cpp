class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int maxArea = -1;
        while (l < r) {
            int minHeight = min(heights.at(l), heights.at(r)), width = (r - l);
            int currArea = minHeight * width;
            if (maxArea < currArea) {maxArea = currArea;}
            if (heights.at(l) < heights.at(r)) {
                l++;
            }
            else {
                r--;
            }
        }
        return maxArea;
    }
};
