// 13:09
class MedianFinder {
    multiset<int> lo, hi;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (hi.empty() || num < *hi.begin()) {
            lo.insert(num);
        } else {
            hi.insert(num);
        }
        if (lo.size() > hi.size()) {
            auto it = prev(lo.end());
            hi.insert(*it);
            lo.erase(it);
        } else if (hi.size() > lo.size() + 1) {
            auto it = hi.begin();
            lo.insert(*it);
            hi.erase(it);
        }
    }
    
    double findMedian() {
        // cout << lo.size() << ' ' << hi.size() << endl;
        // cout << "lo:"; for (auto x : lo) cout << ' ' << x; cout << endl;
        // cout << "hi:"; for (auto x : hi) cout << ' ' << x; cout << endl;
        if (lo.size() == hi.size()) {
            return (0.0f + *lo.rbegin() + *hi.begin()) / 2;
        }
        return *hi.begin();
    }
};
