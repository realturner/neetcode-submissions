// 12:26
class LRUCache {
    list<int> keys;
    unordered_map<int,pair<int,list<int>::iterator>> cache;
    const int limit;
public:
    LRUCache(int capacity): limit(capacity) {        
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }
        auto &[val, lit] = it->second;
        keys.erase(lit);
        keys.push_back(key);
        lit = prev(keys.end());
        return val;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            keys.erase(it->second.second);
        } else if (keys.size() == limit) {
            cache.erase(keys.front());
            keys.pop_front();
        }
        keys.push_back(key);
        cache[key] = {value, prev(keys.end())};
    }
};
