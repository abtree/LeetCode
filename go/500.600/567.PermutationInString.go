package main

import "fmt"

func checkInclusion(s1 string, s2 string) bool {
	ss1, ss2 := len(s1), len(s2)
	if ss2 < ss1 {
		return false
	}
	va := [26]int{}
	vb := [26]int{}
	for _, c := range s1 {
		va[c-'a']++
	}
	for i := 0; i < ss1; i++ {
		vb[s2[i]-'a']++
	}
	if va == vb {
		return true
	}
	i := ss1
	for i < ss2 {
		vb[s2[i-ss1]-'a']--
		vb[s2[i]-'a']++
		if va == vb {
			return true
		}
		i++
	}
	return false
}

func checkInclusion1(s1 string, s2 string) bool {
	ss1, ss2 := len(s1), len(s2)
	if ss2 < ss1 {
		return false
	}
	dp := [26]int{}
	for i := 0; i < ss1; i++ {
		dp[s1[i]-'a']++
		dp[s2[i]-'a']--
	}
	diff := 0
	for _, c := range dp {
		if c != 0 {
			diff++
		}
	}
	if diff == 0 {
		return true
	}
	for i := ss1; i < ss2; i++ {
		x, y := s2[i-ss1]-'a', s2[i]-'a'
		if x == y {
			continue
		}
		if dp[x] == 0 {
			diff++
		}
		dp[x]++
		if dp[x] == 0 {
			diff--
		}
		if dp[y] == 0 {
			diff++
		}
		dp[y]--
		if dp[y] == 0 {
			diff--
		}
		if diff == 0 {
			return true
		}
	}
	return false
}

func main() {
	fmt.Println(checkInclusion1("ab", "eidbaooo"), true)
	fmt.Println(checkInclusion1("ab", "eidboaoo"), false)
}
