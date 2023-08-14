package main

import "fmt"

func characterReplacement(s string, k int) int {
	n := len(s)
	ret := 0
	p := 0
	for i := range s {
		if i != p && s[i] == s[p] {
			continue
		}
		ret = max(ret, i-p)
		p = i
	}
	ret = max(ret, n-p)
	ret = min(n, ret+k)
	if k == 0 {
		return ret
	}
	ret = max(ret, check(s, k))
	return ret
}

func check(s string, k int) int {
	n := len(s)
	ret := 0
	p, q, x := 0, 0, 0
	for i := 1; i < n; i++ {
		if s[i] == s[p] {
			continue
		}
		if q == p {
			q = i
		}
		if x >= k {
			ret = max(ret, i-p)
			p, i, x = q, q, 0
		} else {
			x++
		}
	}
	ret = max(ret, n-p)
	return ret
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func characterReplacement1(s string, k int) int {
	n := len(s)
	p, q := 0, 0
	dp := make([]int, 26)
	maxn := 0
	for q < n {
		dp[int(s[q]-'A')]++
		maxn = max(maxn, dp[int(s[q]-'A')])
		if q-p+1-maxn > k {
			dp[s[p]-'A']--
			p++
		}
		q++
	}
	return q - p
}

func main() {
	fmt.Println(characterReplacement1("BAAAB", 2), 5)
	fmt.Println(characterReplacement1("ABBB", 2), 4)
	fmt.Println(characterReplacement1("AAAB", 0), 3)
	fmt.Println(characterReplacement1("ABAB", 2), 4)
	fmt.Println(characterReplacement1("AABABBA", 1), 4)
}
