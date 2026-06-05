// 13:49 x 13:58
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        const int n = nums.size();
        vector dp(n, vector<int>(n, -1));
        auto go = [&](this auto &&go, int i, int j) -> int {
            if (i > j) {
                return 0;
            }
            auto &ans = dp[i][j];
            if (ans == -1) {
                for (int k = i; k <= j; k++) {
                    ans = max(ans, go(i, k - 1) + go(k + 1, j) + nums[k] * nums[i - 1] * nums[j + 1]);
                }
            }
            return ans;
        };
        return go(1, n - 2);
    }
};

/*
a, b, c, d, e
if select c:
a, b,    d, e
*/