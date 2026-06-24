class Twitter {
public:
    int timer;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        priority_queue<vector<int>> pq;
        // Add user's own tweets
        if (tweets.count(userId)) {
            int idx = tweets[userId].size() - 1;
            pq.push({
                tweets[userId][idx].first,  // timestamp
                tweets[userId][idx].second, // tweetId
                userId,
                idx
            });
        }

        // Add latest tweet from each followee
        for (int followee : following[userId]) {
            if (tweets.count(followee) && !tweets[followee].empty()) {
                int idx = tweets[followee].size() - 1;
                pq.push({
                    tweets[followee][idx].first,
                    tweets[followee][idx].second,
                    followee,
                    idx
                });
            }
        }

        while (!pq.empty() && result.size() < 10) {
            auto cur = pq.top();
            pq.pop();
            int tweetId = cur[1];
            int user = cur[2];
            int idx = cur[3];
            result.push_back(tweetId);

            // Push previous tweet of the same user
            if (idx > 0) {
                pq.push({
                    tweets[user][idx - 1].first,
                    tweets[user][idx - 1].second,
                    user,
                    idx - 1
                });
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};