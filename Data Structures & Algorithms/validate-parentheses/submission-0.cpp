class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        auto attempt = [&](char ch) -> bool {
            if (st.empty() || st.top() != ch) {
                return false;
            }
            st.pop();
            return true;
        };
        for (char ch : s) {
            switch (ch) {
                case '(': case '[': case '{':
                    st.push(ch);
                    break;
                case ')': if (!attempt('(')) return false; break;
                case ']': if (!attempt('[')) return false; break;
                case '}': if (!attempt('{')) return false; break;
            }
        }
        return st.empty();
    }
};
