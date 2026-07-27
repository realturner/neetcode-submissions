class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> counts;
        for (int x : hand) {
            counts[x]++;
        }
        while (!counts.empty()) {
            auto x = counts.begin()->first;
            int y = x;
            while (counts.count(y - 1)) {
                y--;
            }
            while (x - y + 1 < groupSize && counts.count(x + 1)) {
                x++;
            }
            if (x - y + 1 < groupSize) {
                return false;
            }
            // cout << y << " ~ " << x << endl;
            for (int i = y; i < y + groupSize; i++) {
                if (counts[i] == 1) {
                    counts.erase(i);
                } else {
                    counts[i]--;
                }
            }
        }
        return true;
    }
};
