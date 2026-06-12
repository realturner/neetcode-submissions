// 20:29
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const int n = digits.size();
        vector<string> codes = {
                   "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs","tuv", "wxyz"
        };
        vector<string> ans;
        string curr;
        auto go = [&](this auto &&go, int i) -> void {
            if (i == n) {
                if (i > 0) {
                    ans.push_back(curr);
                }
                return;
            }
            for (char ch : codes[digits[i] - '2']) {
                curr.push_back(ch);
                go(i + 1);
                curr.pop_back();
            }
        };
        go(0);
        return ans;
    }
};
