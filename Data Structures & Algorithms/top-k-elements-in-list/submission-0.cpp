class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> heap; // pair<int,int> = pair<freq, val>
        map<int,int> data; // map<int,int> = map<val, freq>
        for(const auto& num : nums) {
            data[num]++;
        }
        for(const auto& i : data) {
            heap.push({i.second, i.first});
        }
        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
