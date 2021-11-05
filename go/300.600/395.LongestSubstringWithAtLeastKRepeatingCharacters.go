package main

import "fmt"

func longestSubstring(s string, k int) int {
	byts := []byte(s)
	return longest(byts, k)
}

func longest(byts []byte, k int) int{
	dp := make([]int, 26)
	for _, b := range byts{
		dp[b-'a']++
	}
	x := check(dp, k)
	if x > 0{
		return x
	}
	ll, p := 0, 0
	for i, c := range byts{
		if dp[c-'a'] < k {
			if i -p>=k{
				ll = max(ll, longest(byts[p:i], k))
			}
			p = i+1
		}
	}
	if len(byts) -p>=k{
		ll = max(ll, longest(byts[p:], k))
	}
	return ll
}

func check(dp []int, k int) int{
	ret := 0
	for _, v := range dp{
		if v > 0 && v < k{
			return 0
		}
		ret += v
	}
	return ret
}

func max(i, j int) int{
	if i > j{
		return i
	}
	return j
}

func main() {
	fmt.Println(longestSubstring("bbaaacbd", 3), 3)
	fmt.Println(longestSubstring("aabcabb", 3), 0)
	fmt.Println(longestSubstring("aaabb", 3), 3)
	fmt.Println(longestSubstring("ababbc", 2), 5)
}