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
        stack<string> st;
        st.push("JFK");
        while (!st.empty()) {
            auto u = st.top();
            auto &nexts = adjs[u];
            if (nexts.empty()) {
                ans.push_back(u);
                st.pop();
            } else {
                auto v = nexts.back();
                nexts.pop_back();
                st.push(v);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
