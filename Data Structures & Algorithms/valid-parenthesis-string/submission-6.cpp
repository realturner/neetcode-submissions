// 14:51
class Solution {
public:
    bool checkValidString(string &s) {
        const int n = s.length();
        stack<int> left, star;
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case '(': left.push(i); break;
                case '*': star.push(i); break;
                case ')':
                    if (left.empty() && star.empty()) {
                        return false;
                    } else if (!left.empty()) {
                        left.pop();
                    } else {
                        star.pop();
                    }
                    break;
            }
        }
        while (!left.empty()) {
            if (star.empty() || star.top() < left.top()) {
                return false;
            }
            left.pop();
            star.pop();
        }
        return true;
    }
};
