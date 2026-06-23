// 10:49
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(), points.begin() + k, points.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });
        points.resize(k);
        return points;
    }
};
