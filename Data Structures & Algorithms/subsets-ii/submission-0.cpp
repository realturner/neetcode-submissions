// 12:42
class Solution {
    vector<pair<int,int>> buildCounts(vector<int> &nums) {
        unordered_map<int,int> counts;
        for (int x : nums) {
            counts[x]++;
        }
        return {counts.begin(), counts.end()};
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        const int n = nums.size();
        auto counts = buildCounts(nums);
        vector<vector<int>> ans;
        vector<int> curr;
        auto go = [&](this auto &&go, int i) -> void {
            if (i == counts.size()) {
                ans.push_back(curr);
                return;
            }
            auto [val, cnt] = counts[i];
            auto k = curr.size();
            go(i + 1);
            for (int j = 1; j <= cnt; j++) {
                curr.push_back(val);
                go(i + 1);
            }
            curr.resize(k);
        };
        go(0);
        return ans;
    }
};
