// 10:34
class Twitter {
    unordered_map<int,list<pair<int,int>>> userPosts;
    unordered_map<int,unordered_set<int>> userFollowings;
    int timer = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userPosts[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,list<pair<int,int>>::reverse_iterator> cursors;
        auto registerCursor = [&](int fid) -> void {
            auto &posts = userPosts[fid];
            auto it = posts.rbegin();
            if (it != posts.rend()) {
                pq.push({it->first, fid});
                cursors[fid] = it;
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
            auto [ts, fid] = pq.top();
            pq.pop();
            auto &curr = userPosts[fid];
            auto &it = cursors[fid];
            ans.push_back(it->second);
            if (++it != curr.rend()) {
                pq.push({it->first, fid});
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
