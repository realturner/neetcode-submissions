// 09:54
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        auto go = [&](this auto &&go, int l, int remain) -> void {
            if (l == 0 && remain == 0) {
                ans.push_back(curr);
                return;
            }
            if (l > 0) {
                curr.push_back(')');
                go(l - 1, remain);
                curr.pop_back();
            }
            if (remain > 0) {
                curr.push_back('(');
                go(l + 1, remain - 1);
                curr.pop_back();
            }
        };
        go(0, n);
        return ans;
    }
};
