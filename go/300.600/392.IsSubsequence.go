package main

import "fmt"

func isSubsequence(s string, t string) bool {
	ss, ps, st, pt := len(s), 0, len(t), 0
	for ps < ss && pt < st {
		if s[ps] == t[pt] {
			ps++
		}
		pt++
	}
	return ps == ss
}

func main() {
	fmt.Println(isSubsequence("abc", "ahbgdc"), true)
	fmt.Println(isSubsequence("axc", "ahbgdc"), false)
}