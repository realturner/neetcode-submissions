// 10:34
class Twitter {
    unordered_map<int,list<pair<int,int>>> userPosts;
    unordered_map<int,unordered_set<int>> userFollowings;
    int timer = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        auto &curr = userPosts[userId];
        curr.push_back({timer++, tweetId});
        if (curr.size() > 10) {
            curr.pop_front();
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        map<int,int> pq;
        unordered_map<int,list<pair<int,int>>::reverse_iterator> cursors;
        auto registerCursor = [&](int fid) -> void {
            auto &posts = userPosts[fid];
            auto it = posts.rbegin();
            if (it != posts.rend()) {
                pq[it->first] = fid;
                cursors[fid] = it;
            }
            if (pq.size() > 10) {
                cursors.erase(pq.begin()->second);
                pq.erase(pq.begin());
            }
        };
        registerCursor(userId);
        for (auto fid : userFollowings[userId]) {
            if (fid != userId) {
                registerCursor(fid);
            }
        }
        vector<int> ans;
        while (!pq.empty() && ans.size() < 10) {
            auto [ts, fid] = *pq.rbegin();
            pq.erase(prev(pq.end()));
            auto &curr = userPosts[fid];
            auto &it = cursors[fid];
            ans.push_back(it->second);
            if (++it != curr.rend()) {
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
