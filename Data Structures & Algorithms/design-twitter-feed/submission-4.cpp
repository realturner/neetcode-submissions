// 10:34
class Twitter {
    const int feedLimit = 10;
    unordered_map<int,list<pair<int,int>>> userPosts;
    unordered_map<int,unordered_set<int>> userFollowings;
    int timer = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        auto &curr = userPosts[userId];
        curr.push_back({timer++, tweetId});
        if (curr.size() > feedLimit) {
            curr.pop_front();
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        map<int,int> pq;
        unordered_map<int,list<pair<int,int>>::iterator> cursors;
        auto registerCursor = [&](int fid) -> void {
            auto &posts = userPosts[fid];
            auto it = posts.end();
            if (it != posts.begin()) {
                --it;
                pq[it->first] = fid;
                cursors[fid] = it;
            }
            if (pq.size() > feedLimit) {
                auto begin = pq.begin();
                cursors.erase(begin->second);
                pq.erase(begin);
            }
        };
        registerCursor(userId);
        for (auto fid : userFollowings[userId]) {
            if (fid != userId) {
                registerCursor(fid);
            }
        }
        vector<int> ans;
        while (!pq.empty() && ans.size() < feedLimit) {
            auto tail = prev(pq.end());
            auto [ts, fid] = *tail;
            pq.erase(tail);
            auto &curr = userPosts[fid];
            auto &it = cursors[fid];
            ans.push_back(it->second);
            if (it != curr.begin()) {
                --it;
                pq[it->first] = fid;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        userFollowings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userFollowings[followerId].erase(followeeId);
    }
};
