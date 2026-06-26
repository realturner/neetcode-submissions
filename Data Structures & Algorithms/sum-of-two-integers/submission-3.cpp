class Solution {
public:
    int getSum(int a, int b) {
        for (int carry = 0; b; b = carry) {
            carry = (a & b) << 1;
            a ^= b;
        }
        return a;
    }
};
