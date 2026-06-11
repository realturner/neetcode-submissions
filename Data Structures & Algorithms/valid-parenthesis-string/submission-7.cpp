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
                    if (!left.empty()) {
                        left.pop();
                    } else if (!star.empty()) {
                        star.pop();
                    } else {
                        return false;
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
