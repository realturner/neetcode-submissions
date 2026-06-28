// 09:35
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        auto &y = newInterval;
        bool processed = false;
        for (auto &x : intervals) {
            if (x[1] < y[0]) {
                ans.push_back(x);
            } else if (x[0] > y[1]) {
                if (!processed) {
                    ans.push_back(y);
                    processed = true;
                }
                ans.push_back(x);
            } else {
                y = {min(x[0], y[0]), max(x[1], y[1])};
            }
        }
        if (!processed) {
            ans.push_back(y);
        }
        return ans;
    }
};
