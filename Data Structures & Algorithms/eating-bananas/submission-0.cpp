// 09:18
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            int mid = l + (r - l) / 2;
            int acc = 0;
            for (int x : piles) {
                acc += (x - 1) / mid + 1;
            }
            if (acc > h) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
