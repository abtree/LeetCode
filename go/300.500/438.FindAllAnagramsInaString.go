package main

import "fmt"

func findAnagrams(s string, p string) []int {
	ssize, psize := len(s), len(p)
	ret := []int{}
	if ssize < psize {
		return ret
	}
	scount := [26]int{}
	pcount := [26]int{}
	for i := 0; i < psize; i++ {
		scount[s[i]-'a']++
		pcount[p[i]-'a']++
	}
	if scount == pcount {
		ret = append(ret, 0)
	}
	n := ssize - psize
	for i := 0; i < n; i++ {
		scount[s[i]-'a']--
		scount[s[i+psize]-'a']++
		if scount == pcount {
			ret = append(ret, i+1)
		}
	}
	return ret
}

func findAnagrams1(s string, p string) []int {
	ssize, psize := len(s), len(p)
	ret := []int{}
	if ssize < psize {
		return ret
	}
	dp := [26]int{}
	for i, x := range p {
		dp[s[i]-'a']++
		dp[x-'a']--
	}
	differ := 0
	for _, x := range dp {
		if x != 0 {
			differ++
		}
	}
	if differ == 0 {
		ret = append(ret, 0)
	}
	n := ssize - psize
	for i := 0; i < n; i++ {
		x := s[i] - 'a'
		if dp[x] == 1 {
			differ--
		} else if dp[x] == 0 {
			differ++
		}
		dp[x]--
		x = s[i+psize] - 'a'
		if dp[x] == -1 {
			differ--
		} else if dp[x] == 0 {
			differ++
		}
		dp[x]++
		if differ == 0 {
			ret = append(ret, i+1)
		}
	}
	return ret
}

func main() {
	fmt.Println(findAnagrams1("af", "be"))
	fmt.Println(findAnagrams1("cbaebabacd", "abc"))
	fmt.Println(findAnagrams1("aaaaaaaaaa", "aaaaaaaaaaaaa"))
	fmt.Println(findAnagrams1("abab", "ab"))
	fmt.Println(findAnagrams1("aa", "bb"))
}
