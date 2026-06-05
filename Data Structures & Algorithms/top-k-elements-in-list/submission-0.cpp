// 09:42
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int x : nums) {
            freq[x]++;
        }
        vector<pair<int,int>> pairs(freq.begin(), freq.end());
        nth_element(pairs.begin(), pairs.begin() + k, pairs.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
            return a.second > b.second;
        });
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pairs[i].first);
        }
        return ans;
    }
};
