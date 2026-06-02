// 10:57
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a, b;
        auto binaryOp = [&](function<int(int,int)> op) {
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            st.push(op(a, b));
        };
        for (auto &token : tokens) {
            if (token.length() == 1 && !isdigit(token[0])) {
                switch (token[0]) {
                    case '+':
                        binaryOp([](int a, int b) {
                            return a + b;
                        });
                        break;
                    case '-':
                        binaryOp([](int a, int b) {
                            return a - b;
                        });
                        break;
                    case '*':
                        binaryOp([](int a, int b) {
                            return a * b;
                        });
                        break;
                    case '/':
                        binaryOp([](int a, int b) {
                            return a / b;
                        });
                        break;
                }
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
