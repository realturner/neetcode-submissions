// 09:55
class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for (auto &s : strs) {
            ans += to_string(s.length()) + ":" + s;
        }
        return ans;
    }

    vector<string> decode(string &s) {
        const int n = s.length();
        vector<string> ans;
        for (int i = 0, len; i < n; ) {
            len = 0;
            while (s[i] != ':') {
                len = len * 10 + s[i] - '0';
                i++;
            }
            ans.push_back(s.substr(++i, len));
            i += len;
        }
        return ans;
    }
};
