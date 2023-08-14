#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

//355. 设计推特
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        users[userId].push_back(index);
        topic.push_back(tweetId);
        ++index;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        int top = INT_MAX;
        vector<int> ret;
        for (int i = 0; i < 10;++i) {
            int cur = -1;
            for (auto it = users[userId].rbegin(); it != users[userId].rend(); ++it) {
                if (*it < top) {
                    cur = *it;
                    break;
                }
            }
            for (auto flws : userFallow[userId]) {
                for (auto it = users[flws].rbegin(); it != users[flws].rend(); ++it) {
                    if (*it < top) {
                        cur = max(*it, cur);
                        break;
                    }
                }
            }
            if (cur < 0)
                break;
            ret.push_back(topic[cur]);
            top = cur;
        }
        return ret;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        userFallow[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        userFallow[followerId].erase(followeeId);
    }
private:
    int index{};    //递增id（对应话题的下标）
    vector<int> topic{};    //话题
    unordered_map<int, vector<int>> users;  //用户和对应的话题
    unordered_map<int, unordered_set<int>> userFallow; //用户和对应的关注
};

int main(int argc, char const* argv[]) {
    Twitter tw;
    tw.postTweet(1, 5);
    auto& r1 = tw.getNewsFeed(1);
    cout << "[";
    for (auto x : r1) {
        cout << x << " , ";
    }
    cout << "]" << endl;
    tw.follow(1, 2);
    tw.postTweet(2, 6);
    auto& r2 = tw.getNewsFeed(1);
    cout << "[";
    for (auto x : r2) {
        cout << x << " , ";
    }
    cout << "]" << endl;
    tw.unfollow(1, 2);
    auto& r3 = tw.getNewsFeed(1);
    cout << "[";
    for (auto x : r3) {
        cout << x << " , ";
    }
    cout << "]" << endl;
    return 0;
}
