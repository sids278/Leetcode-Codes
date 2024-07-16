class Twitter {
public:
    map<int,set<pair<int,int>>>tweets;
    map<int,set<int>>follower;
    int timer=0;
    Twitter() {
        // just the intialization
        
    }
    
    void postTweet(int userId, int tweetId) {
        timer++;
        tweets[userId].insert({timer,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
       vector<pair<int,int>> v;
        for(auto it:follower[userId])
            for(auto i:tweets[it])
                v.push_back(i);
        for(auto i:tweets[userId])
                v.push_back(i);
        sort(v.begin(),v.end());
        vector<int>ans;
        int n=v.size()-1;
        while(n>=0 and ans.size()<10)
        {
            ans.push_back(v[n].second);
            n--;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */