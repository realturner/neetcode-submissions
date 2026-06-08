// 16:08
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> normedId;
        vector<vector<string>> ans;
        for (auto &s : strs) {
            string norm(s);
            sort(norm.begin(), norm.end());
            auto it = normedId.find(norm);
            if (it == normedId.end()) {
                normedId[norm] = normedId.size();
                ans.push_back({s});
            } else {
                ans[it->second].push_back(s);
            }
        }
        return ans;
    }
};
