// 14:35
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && seen.count(n) == 0) {
            seen.insert(n);
            int next = 0;
            for (int x = n; x; x /= 10) {
                next += (x % 10) * (x % 10);
            }
            n = next;
        }
        return n == 1;
    }
};
