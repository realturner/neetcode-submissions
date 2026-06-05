// 21:08
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        const int n = triplets.size();
        vector<int> curr(3, 0);
        for (auto &t : triplets) {
            if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                for (int i = 0; i < 3; i++) {
                    curr[i] = max(curr[i], t[i]);
                }
            }
        }
        return curr == target;
    }
};
