class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        for (int i = 0, bit = 1, carry = 0; i < 32; i++, bit <<= 1) {
            ans |= (a & bit) ^ (b & bit) ^ carry;
            carry = (a & bit) & (b & bit) | (b & bit) & (carry & bit) | 
                (carry & bit) & (a & bit);
            carry <<= 1;
        }
        return ans;
    }
};
