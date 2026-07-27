class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26);
        for (char ch : tasks) {
            counts[ch - 'A']++;
        }
        priority_queue<int> pq;
        for (int x : counts) {
            if (x > 0) {
                pq.push(x);
            }
        }
        queue<pair<int,int>> q; // (until, remain)
        int time = 0;
        while (!pq.empty()) {
            ++time;
            int remain = pq.top() - 1;
            pq.pop();
            if (remain > 0) {
                q.push({time + n, remain});
            }
            if (pq.empty() && !q.empty()) {
                time = q.front().first;
            }
            while (!q.empty() && q.front().first <= time) {
                pq.push(q.front().second);
                q.pop();
            }
        }
        return time;
    }
};
