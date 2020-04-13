class Twitter {
public:

    typedef struct twId{
        int tweetId;
        int time;
    }twId;
    unordered_map<int, vector<twId*>> twitters;
    unordered_map<int, set<int>> follows;
    int count = 0;
    /** Initialize your data structure here. */
    Twitter() {

    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        twId* it = new twId();
        it->tweetId = tweetId;
        it->time = count;
        twitters[userId].push_back(it);
        count++;
    }

    static bool comp(twId* a, twId* b){
        return a->time > b->time;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        vector<twId*> tws = twitters[userId];
        set<int> myFollows = follows[userId];
        auto iter = myFollows.begin();
        while(iter != myFollows.end()){
            tws.insert(tws.end(), twitters[*iter].begin(), twitters[*iter].end());
            iter++;
        }
        sort(tws.begin(), tws.end(), comp);
        for(int i = 0; i < tws.size(); ++i){
            if(i >= 10) break;
            res.push_back(tws[i]->tweetId);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            follows[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId)
            follows[followerId].erase(followeeId);
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