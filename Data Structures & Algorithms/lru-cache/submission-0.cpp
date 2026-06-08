// 12:26
class LRUCache {
    map<int,int> timeKey;
    unordered_map<int,pair<int,int>> keyValTime;
    int timer = 0;
    const int limit;
public:
    LRUCache(int capacity): limit(capacity) {
        
    }
    
    int get(int key) {
        ++timer;
        auto it = keyValTime.find(key);
        if (it == keyValTime.end()) {
            return -1;
        }
        int ret = it->second.first;
        timeKey.erase(it->second.second);
        timeKey[timer] = key;
        it->second.second = timer;
        return ret;
    }
    
    void put(int key, int value) {
        ++timer;
        auto it = keyValTime.find(key);
        if (it == keyValTime.end()) {
            keyValTime[key] = {value, timer};
            timeKey[timer] = key;
            if (timeKey.size() > limit) {
                auto it = timeKey.begin();
                keyValTime.erase(it->second);
                timeKey.erase(it);
            }
        } else {
            timeKey.erase(it->second.second);
            timeKey[timer] = key;
            it->second = {value, timer};
        }
    }
};
