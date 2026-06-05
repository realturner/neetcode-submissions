// 21:08
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a = false, b = false, c = false;
        for (auto &t : triplets) {
            a = a || t[0] == target[0] && t[1] <= target[1] && t[2] <= target[2];
            b = b || t[0] <= target[0] && t[1] == target[1] && t[2] <= target[2];
            c = c || t[0] <= target[0] && t[1] <= target[1] && t[2] == target[2];
            if (a && b && c) {
                return true;
            }
        }
        return false;
    }
};
