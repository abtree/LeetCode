package main

import "fmt"

func isIsomorphic(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	size := len(s)
	dp := map[byte]byte{}
	ep := map[byte]byte{}
	for i := 0; i < size; i++ {
		if c, ok := dp[s[i]]; ok {
			if c != t[i] {
				return false
			} else {
				continue
			}
		}
		if _, ok := ep[t[i]]; ok {
			return false
		}
		dp[s[i]] = t[i]
		ep[t[i]] = s[i]
	}
	return true
}

func main() {
	fmt.Printf("%v -> false \n", isIsomorphic("badc", "baba"))
	fmt.Printf("%v -> true \n", isIsomorphic("egg", "add"))
	fmt.Printf("%v -> false \n", isIsomorphic("foo", "bar"))
	fmt.Printf("%v -> true \n", isIsomorphic("paper", "title"))
}
