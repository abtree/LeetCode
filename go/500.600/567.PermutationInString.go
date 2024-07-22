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

func main() {
	fmt.Println(checkInclusion("ab", "eidbaooo"))
	fmt.Println(checkInclusion("ab", "eidboaoo"))
}
