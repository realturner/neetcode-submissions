class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        int curr = 0, cand = 0, minVal = 0;
        for (int i = 0; i < n; i++) {
            curr += gas[i] - cost[i];
            if (curr < minVal) {
                cand = i + 1;
                minVal = curr;
            }
        }
        return curr < 0 ? -1 : cand;
    }
};
