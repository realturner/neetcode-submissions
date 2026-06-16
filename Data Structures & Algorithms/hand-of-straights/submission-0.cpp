// 09:42
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        const int n = hand.size();
        if (groupSize == 1) {
            return true;
        } else if (n % groupSize) {
            return false;
        }
        sort(hand.begin(), hand.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // tail, head
        for (int x : hand) {
            if (pq.empty() || x < pq.top().first) {
                pq.push({x + 1, x});
            } else if (x > pq.top().first) {
                return false;
            } else {
                auto [tail, head] = pq.top();
                pq.pop();
                if (tail - head + 1 < groupSize) {
                    pq.push({tail + 1, head});
                }
            }
        }
        return pq.empty();
    }
};
