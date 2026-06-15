class Twitter {
public:
    unordered_map<int, vector<vector<int>>> tweets;
    unordered_map<int, unordered_set<int>> friends;
    int time;
    Twitter(){
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
      tweets[userId].push_back({time,tweetId});
      time++;
      
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        for(auto ele: tweets[userId]){
            minheap.push(ele);
            if(minheap.size()>10){
                minheap.pop();
            }
        }
        for(int f: friends[userId]){
            for(int i=tweets[f].size()-1; i>=0; i--){
                if(minheap.size()==10 && tweets[f][i][0]<minheap.top()[0]){
                    break;
                }
                else{
                    minheap.push(tweets[f][i]);
                    if(minheap.size()>10){
                        minheap.pop();
                    }
                }
            }
        }
        vector<int> ans;
        while(minheap.empty()==false){
            int top = minheap.top()[1];
            minheap.pop();
            ans.push_back(top);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            friends[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if(friends[followerId].count(followeeId)){
            friends[followerId].erase(followeeId);
        }
    }
};
