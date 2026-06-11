// 10:97
class TimeMap {
    unordered_map<string,vector<pair<int,string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            return "";
        }
        auto &curr = it->second;
        auto jt = upper_bound(curr.begin(), curr.end(), timestamp, [](int x, pair<int,string> &item) {
            return x < item.first;
        });
        if (jt == curr.begin()) {
            return "";
        }
        return prev(jt)->second;
    }
};
