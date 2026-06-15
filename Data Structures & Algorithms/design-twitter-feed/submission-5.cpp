class Twitter {
public:
    // (userId, tweetId) for all tweets in time order
    vector<pair<int,int>> tweets;
    // friends[u] = set of users that u follows
    vector<unordered_set<int>> friends;

    Twitter() : friends(100) {}  // or larger if needed

    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> feeds;
        int count = 0;

        for (int i = (int)tweets.size() - 1; i >= 0 && count < 10; --i) {
            int tweeter = tweets[i].first;
            if (tweeter == userId || friends[userId-1].count(tweeter)) {
                feeds.push_back(tweets[i].second);
                count++;
            }
        }
        return feeds;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        friends[followerId-1].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        friends[followerId-1].erase(followeeId);
    }
};
