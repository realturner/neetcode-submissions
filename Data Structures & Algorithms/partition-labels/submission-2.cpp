// 14:48
class Solution {
public:
    vector<int> partitionLabels(string &s) {
        const int n = s.length();
        unordered_map<char,int> right;
        for (int i = 0; i < n; i++) {
            right[s[i]] = i;
        }
        vector<int> ans;
        for (int i = 0, p = 0, q = 0; i < n; i++) {
            q = max(q, right[s[i]]);
            if (q == i) {
                ans.push_back(q - p + 1);
                p = i + 1;
            }
        }
        return ans;
    }
};
