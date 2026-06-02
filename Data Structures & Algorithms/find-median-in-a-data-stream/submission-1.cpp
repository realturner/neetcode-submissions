// 14:24
class MedianFinder {
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<>> hi;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (lo.empty() || lo.top() < num) {
            hi.push(num);
        } else {
            lo.push(num);
        }
        if (lo.size() > hi.size()) {
            hi.push(lo.top());
            lo.pop();
        } else if (hi.size() > lo.size() + 1) {
            lo.push(hi.top());
            hi.pop();           
        }
    }
    
    double findMedian() {
        if (lo.size() == hi.size()) {
            return (0.0 + lo.top() + hi.top()) / 2;
        }
        return hi.top();
    }
};
