// 09:42
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int n = nums.size();
        unordered_map<int,int> freq;
        for (int x : nums) {
            freq[x]++;
        }
        unordered_map<int,vector<int>> valsByFreq;
        for (auto &[val, f] : freq) {
            valsByFreq[f].push_back(val);
        }
        vector<int> ans;
        for (int i = n; i > 0 && ans.size() < k; i--) {
            if (valsByFreq.count(i)) {
                for (int x : valsByFreq[i]) {
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }
};
