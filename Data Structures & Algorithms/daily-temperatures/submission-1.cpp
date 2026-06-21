// 09:34
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        auto &t = temperatures;
        const int n = t.size();
        vector<int> ans(n, 0);
        for (int i = n - 2, j; i >= 0; i--) {
            for (j = i + 1; j < n && ans[j] > 0 && t[j] <= t[i]; j += ans[j]);
            if (j < n && t[j] > t[i]) {
                ans[i] = j - i;
            }
        }
        return ans;
    }
};
