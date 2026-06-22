// 08:57
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        const int n = digits.size();
        int carry = 1;
        for (int i = n - 1; i >= 0 && carry > 0; i--) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
