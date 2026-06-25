class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());
        while (stones.size() > 1) {
            pop_heap(stones.begin(), stones.end());
            pop_heap(stones.begin(), stones.end() - 1);
            int y = stones[stones.size() - 1];
            int x = stones[stones.size() - 2];
            if (x == y) {
                stones.resize(stones.size() - 2);
            } else {
                stones.pop_back();
                stones.back() = y - x;
                push_heap(stones.begin(), stones.end());
            }
        }
        return stones.empty() ? 0 : stones.front();
    }
};
