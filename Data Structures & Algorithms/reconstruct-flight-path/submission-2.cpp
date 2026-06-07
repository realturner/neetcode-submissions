// 15:53 x 16:30
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        const int n = tickets.size();
        unordered_map<string, map<string,int>> adjs;
        for (auto &e : tickets) {
            adjs[e[0]][e[1]]++;
        }
        vector<string> curr = { "JFK" };
        auto go = [&](this auto &&go) -> bool {
            if (curr.size() == n + 1) {
                return true;
            }
            for (auto &[v, cnt] : adjs[curr.back()]) {
                if (cnt > 0) {
                    curr.push_back(v);
                    --cnt;
                    if (go()) {
                        return true;
                    }
                    ++cnt;
                    curr.pop_back();
                }
            }
            return false;
        };
        go();
        return curr;
    }
};
