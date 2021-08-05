package main

import (
	"fmt"
	"math"
)

type Twitter struct {
	Index   int                      //自增id（话题用）
	Users   map[int][]int            //用户和对应的话题
	Follows map[int]map[int]struct{} //用户和对应的关注
	Topics  []int                    //话题
}

/** Initialize your data structure here. */
func Constructor() Twitter {
	return Twitter{
		Users:   make(map[int][]int),
		Follows: make(map[int]map[int]struct{}),
		Topics:  make([]int, 0),
	}
}

/** Compose a new tweet. */
func (this *Twitter) PostTweet(userId int, tweetId int) {
	this.Users[userId] = append(this.Users[userId], this.Index)
	this.Topics = append(this.Topics, tweetId)
	this.Index++
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
func (this *Twitter) GetNewsFeed(userId int) []int {
	top := math.MaxInt32
	ret := []int{}
	for i := 0; i < 10; i++ {
		cur := -1
		size := len(this.Users[userId]) - 1
		for size >= 0 {
			if this.Users[userId][size] < top {
				cur = this.Users[userId][size]
				break
			}
			size--
		}
		for k := range this.Follows[userId] {
			size := len(this.Users[k]) - 1
			for size >= 0 {
				if this.Users[k][size] < top {
					cur = max(this.Users[k][size], cur)
					break
				}
				size--
			}
		}
		if cur < 0 {
			break
		}
		ret = append(ret, this.Topics[cur])
		top = cur
	}
	return ret
}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
func (this *Twitter) Follow(followerId int, followeeId int) {
	if k, ok := this.Follows[followerId]; !ok || k == nil {
		this.Follows[followerId] = make(map[int]struct{})
		this.Follows[followerId][followeeId] = struct{}{}
	} else {
		_, f := this.Follows[followerId][followeeId]
		if !f {
			this.Follows[followerId][followeeId] = struct{}{}
		}
	}
}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
func (this *Twitter) Unfollow(followerId int, followeeId int) {
	if k, ok := this.Follows[followerId]; !ok || k == nil {
		return
	}
	delete(this.Follows[followerId], followeeId)
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func main() {
	cls := Constructor()
	cls.PostTweet(1, 5)
	fmt.Println(cls.GetNewsFeed(1))
	cls.Follow(1, 2)
	cls.PostTweet(2, 6)
	fmt.Println(cls.GetNewsFeed(1))
	cls.Unfollow(1, 2)
	fmt.Println(cls.GetNewsFeed(1))
}
