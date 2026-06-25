class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26, 0);
        for (char ch : tasks) {
            counts[ch - 'A']++;
        }
        int maxf = 0, maxCount = 0;
        for (int i = 0; i < 26; i++) {
            if (counts[i] > maxf) {
                maxf = counts[i];
                maxCount = 1;
            } else if (counts[i] == maxf) {
                maxCount++;
            }
        }
        int fits = (maxf - 1) * (n + 1) + maxCount;
        return max<int>(fits, tasks.size());
    }
};
