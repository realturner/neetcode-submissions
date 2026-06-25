class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26);
        for (char ch : tasks) {
            counts[ch - 'A']++;
        }
        priority_queue<int> pq; // remain
        queue<pair<int,int>> q; // until, remain
        for (int i = 0; i < 26; i++) {
            if (counts[i] > 0) {
                pq.push(counts[i]);
            }
        }
        int ans = 0;
        while (pq.size() + q.size() > 0) {
            if (pq.empty()) {
                ans = q.front().first;
            }
            while (!q.empty() && q.front().first <= ans) {
                pq.push(q.front().second);
                q.pop();
            }
            int remain = pq.top();
            pq.pop();
            ans++;
            if (remain > 1) {
                q.push({ans + n, remain - 1});
            }
        }
        return ans;
    }
};
