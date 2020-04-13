class Twitter {
private:
    map<int, set<int>> user_follow;
    vector<int> messages;
    vector<int> messages_poster;

public:
    /** Initialize your data structure here. */
    Twitter() {
        user_follow.clear();
        messages.clear();
        messages_poster.clear();
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        messages.push_back(tweetId);
        messages_poster.push_back(userId);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ret;
        int cnt = 10, index = messages.size() - 1;
        while (cnt && index >= 0) {
            if (messages_poster[index] == userId)
                ret.push_back(messages[index]);
            else if (user_follow[userId].count(messages_poster[index]))
                ret.push_back(messages[index]);
            else cnt++;
            cnt--, index--;
        }
        return ret;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        user_follow[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        user_follow[followerId].erase(followeeId);
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