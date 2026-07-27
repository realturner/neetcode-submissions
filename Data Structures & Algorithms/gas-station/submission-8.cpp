class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        int ans = 0, netGain = 0, gainMin = 0;
        for (int i = 0; i < n; i++) {
            netGain += gas[i] - cost[i];
            if (netGain < gainMin) {
                ans = i + 1;
                gainMin = netGain;
            }
        }
        return netGain >= 0 ? ans : -1;
    }
};
