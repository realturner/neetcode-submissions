// 10:34
class Twitter {
    unordered_map<int,vector<pair<int,int>>> userPosts;
    unordered_map<int,unordered_set<int>> userFollowings;
    int timer = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userPosts[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int,int,int>> pq;
        auto registerCursor = [&](int fid) -> void {
            auto &posts = userPosts[fid];
            int remain = posts.size();
            if (remain > 0) {
                pq.push({posts[remain - 1].first, fid, remain});
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
            auto [ts, fid, remain] = pq.top();
            pq.pop();
            auto &curr = userPosts[fid];
            ans.push_back(curr[--remain].second);
            if (remain > 0) {
                pq.push({curr[remain - 1].first, fid, remain});
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
