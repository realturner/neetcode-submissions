// 10:97
class TimeMap {
    unordered_map<string,map<int,string>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            return "";
        }
        auto &curr = it->second;
        auto jt = curr.upper_bound(timestamp);
        if (jt == curr.begin()) {
            return "";
        }
        return prev(jt)->second;
    }
};
