class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count the frequencies using a hash map
        unordered_map<int, int> freq;
        for (const auto& num : nums) {
            freq[num]++;
        }

        // Step 2: Move the map contents into a vector of pairs {frequency, element}
        // We put frequency first so it naturally sorts by frequency
        vector<pair<int, int>> freqPairs;
        for (const auto& pair : freq) {
            freqPairs.push_back({pair.second, pair.first});
        }

        // Step 3: Sort the vector in descending order of frequency
        sort(freqPairs.rbegin(), freqPairs.rend());

        // Step 4: Extract the top k elements
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(freqPairs[i].second);
        }

        return res;
    }
};
