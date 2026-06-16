// 09:12
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int n = position.size();
        vector<int> indices(n);
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return position[i] > position[j];
        });
        int ans = 0;
        double curr = 0.0;
        for (int i : indices) {
            double eta = (double) (target - position[i]) / speed[i];
            if (eta > curr + 1e-5) {
                ans++;
                curr = eta;
            }
        }
        return ans;
    }
};
