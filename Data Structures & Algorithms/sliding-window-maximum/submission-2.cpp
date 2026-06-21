// 09:17
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> segs(n << 2, INT_MIN);
        auto build = [&](this auto &&build, int p, int l, int r) -> void {
            if (l == r) {
                segs[p] = nums[l];
                return;
            }
            int mid = l + (r - l) / 2;
            build(p * 2 + 1, l, mid);
            build(p * 2 + 2, mid + 1, r);
            segs[p] = max(segs[2 * p + 1], segs[2 * p + 2]);
        };
        build(0, 0, n - 1);
        auto query = [&](this auto &&query, int p, int i, int j, int l, int r) -> int {
            if (l == r) {
                return segs[p];
            }
            int mid = l + (r - l) / 2;
            int ans = INT_MIN;
            if (mid >= i) {
                ans = max(ans, query(2 * p + 1, i, j, l, mid));
            }
            if (mid + 1 <= j) {
                ans = max(ans, query(2 * p + 2, i, j, mid + 1, r));
            }
            return ans;
        };
        vector<int> ans;
        for (int i = 0; i + k <= n; i++) {
            ans.push_back(query(0, i, i + k - 1, 0, n - 1));
        }
        return ans;
    }
};
