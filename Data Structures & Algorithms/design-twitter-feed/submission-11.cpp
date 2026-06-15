class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<vector<int>>> tweet;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        int size = tweet[userId].size();
        for(int i=size-1; i>=0; i--){
            minheap.push(tweet[userId][i]);
            if(minheap.size()==10) break;
        }
        for(int fol: following[userId]){
            int size = tweet[fol].size();
            int count = 0;
            for(int i=size-1; i>=0; i--){
                minheap.push(tweet[fol][i]);
                if(minheap.size()>10) minheap.pop();
                count++;
                if(count==10) break;
            }
        }
        vector<int> ans;
        while(!minheap.empty()){
            auto top = minheap.top();
            ans.push_back(top[1]);
            minheap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId) following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (following[followerId].count(followeeId)){
            following[followerId].erase(followeeId);
        }
    }
};
