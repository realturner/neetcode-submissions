// 10:49
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        const int n = points.size();
        vector<pair<int,int>> items; // dist square, index
        for (int i = 0; i < n; i++) {
            auto &x = points[i][0], &y = points[i][1];
            items.push_back({x * x + y * y, i});
        }
        nth_element(items.begin(), items.begin() + k, items.end());
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(points[items[i].second]);
        }
        return ans;
    }
};
