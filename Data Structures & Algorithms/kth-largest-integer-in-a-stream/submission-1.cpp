// 16:55
class KthLargest {
    priority_queue<int, vector<int>, greater<>> pq;
    const int limit;
public:
    KthLargest(int k, vector<int>& nums): limit(k) {
        for (int x : nums) {
            pq.push(x);
            if (pq.size() > limit) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > limit) {
            pq.pop();
        }
        return pq.top();
    }
};
