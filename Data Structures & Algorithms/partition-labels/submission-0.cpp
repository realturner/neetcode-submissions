// 14:48
class Solution {
public:
    vector<int> partitionLabels(string &s) {
        const int n = s.length();
        vector<pair<int,int>> segs(26, {n, -1});
        for (int i = 0; i < n; i++) {
            auto &seg = segs[s[i] - 'a'];
            seg = { min(seg.first, i), max(seg.second, i) };
        }
        sort(segs.begin(), segs.end());
        vector<int> ans;
        int tail = -1;
        for (int i = 0, p = 0, q = segs[0].second; i < 26 && segs[i].first != n; i++) {
            auto &[a, b] = segs[i];
            if (a > q) {
                ans.push_back(tail);
                p = a;
                q = b;
                tail = q - p + 1;
            } else {
                q = max(q, b);
                tail = q - p + 1;
            }
        }
        ans.push_back(tail);
        return ans;
    }
};
