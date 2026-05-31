// 20:13
class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        vector<bool> visited(n, false);
        queue<int> q;
        visited[0] = true;
        q.push(0);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (i == n - 1) {
                return true;
            }
            const int len = nums[i];
            for (int j = max(0, i - len); j <= min(n - 1, i + len); j++) {
                if (!visited[j]) {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
        return false;
    }
};
