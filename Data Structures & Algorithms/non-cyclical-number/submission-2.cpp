class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        string ns = to_string(n);
        while(true) {
            int total = 0;
            for(auto& c : ns) {
                int ci = c - '0';
                total += ci * ci;
            }
            if(seen.contains(total)) { return false; }
            if(total == 1) { return true; }
            seen.insert(total);
            ns = to_string(total);
        }
    }
};
