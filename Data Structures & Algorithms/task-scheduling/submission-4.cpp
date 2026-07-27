class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        const int len = tasks.size();
        vector<int> counts(26, 0);
        for (char ch : tasks) {
            counts[ch - 'A']++;
        }
        int p = -1, maxCnt = 0;
        for (int i = 0; i < 26; i++) {
            if (counts[i] == 0) {
                continue;
            }
            if (p < 0 || counts[i] > counts[p]) {
                p = i;
                maxCnt = 1;
            } else if (counts[i] == counts[p]) {
                maxCnt++;
            }
        }
        return max(len, (counts[p] - 1) * (n + 1) + maxCnt);
    }
};
