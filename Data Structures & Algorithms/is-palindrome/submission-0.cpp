class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c) {
            return !std::isalnum(c);
        }), s.end());
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return std::tolower(c);
        });
        int left = 0, right = s.length() - 1;
        while(left <= right) {
            if(s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
