// 09:46
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        int cand = 0, curr = 0, grand = 0;
        for (int i = 0; i < n; i++) {
            grand += gas[i] - cost[i];
            if ((curr += gas[i] - cost[i]) < 0) {
                curr = 0;
                cand = i + 1;
            }
        }
        return grand < 0 ? -1 : cand;
    }
};
