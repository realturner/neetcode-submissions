// 15:53 x 16:30
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adjs;
        for (auto &e : tickets) {
            adjs[e[0]].push_back(e[1]);
        }
        for (auto &[u, nexts] : adjs) {
            sort(nexts.begin(), nexts.end(), greater<string>());
        }
        vector<string> ans;
        auto go = [&](this auto &&go, string u) -> void {
            auto &nexts = adjs[u];
            while (!nexts.empty()) {
                auto v = nexts.back();
                nexts.pop_back();
                go(v);
            }
            ans.push_back(u);
        };
        go("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
