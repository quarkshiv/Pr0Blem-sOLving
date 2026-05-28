class Twitter {
public:
   unordered_map<int,set<int>>followmap;
   unordered_map<int,vector<pair<int,int>>>tweets;
   int timer;
    Twitter() {
        timer=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer,tweetId});
        timer++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(auto it : tweets[userId]){
              pq.push(it);
        }
        for(auto followee :  followmap[userId]){
               for(auto it : tweets[followee]){
                    pq.push(it);
               }
        }
        int cnt=0;
        while(pq.size()>0 &&  cnt<10){
               ans.push_back(pq.top().second);
               pq.pop();
               cnt++;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
         followmap[followerId].erase(followeeId);
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