// 08:59
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        const int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        auto go = [&](this auto &&go, int i, int remain) -> void {
            if (remain == 0) {
                ans.push_back(curr);
            }
            for (int j = i; j < n && candidates[j] <= remain; j++) {
                if (j > i && candidates[j] == candidates[j - 1]) {
                    continue;
                }
                curr.push_back(candidates[j]);
                go(j + 1, remain - candidates[j]);
                curr.pop_back();
            }
        };
        go(0, target);
        return ans;
    }
};
