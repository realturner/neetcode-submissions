// 09:50
class CountSquares {
    unordered_map<int,unordered_multiset<int>> pts;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        auto &x = point[0], &y = point[1];
        pts[x].insert(y);
    }
    
    int count(vector<int> point) {
        auto &qx = point[0], &qy = point[1];
        if (pts.count(qx) == 0) {
            return 0;
        }
        int ans = 0;
        for (auto &y : pts[qx]) {
            if (y == qy) {
                continue;
            }
            int width = abs(y - qy);
            auto r = pts.find(qx + width);
            if (r != pts.end()) {
                ans += r->second.count(y) * r->second.count(qy);
            }
            auto l = pts.find(qx - width);
            if (l != pts.end()) {
                ans += l->second.count(y) * l->second.count(qy);
            }
        }
        return ans;
    }
};
