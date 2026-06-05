// 13:49 x 13:58
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        const int n = nums.size();
        vector dp(n, vector<int>(n, 0));
        for (int diff = 0; diff < n; diff++) {
            for (int i = 1, j = i + diff; j < n - 1; i++, j++) {
                auto &curr = dp[i][j];
                for (int k = i; k <= j; k++) {
                    curr = max(curr, nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
                }
            }
        }
        return dp[1][n - 2];
    }
};

/*
a, b, c, d, e
if select c:
a, b,    d, e
*/