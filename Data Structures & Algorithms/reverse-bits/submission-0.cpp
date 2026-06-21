// 10:01
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0, s = 1, t = 1 << 31;
        for (int i = 0; i < 32; i++) {
            if (n & s) {
                ans |= t;
            }
            s <<= 1;
            t >>= 1;
        }
        return ans;
    }
};
