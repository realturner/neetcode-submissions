// 16:08
#include<cstring>
class Solution {
    int freqs[26];
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> normedId;
        vector<vector<string>> ans;
        for (auto &s : strs) {
            memset(freqs, 0, sizeof(freqs));
            for (char ch : s) {
                freqs[ch - 'a']++;
            }
            string norm;
            for (int i = 0; i < 26; i++) {
                norm += to_string(freqs[i]) + ';';
            }
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
