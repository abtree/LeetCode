package main

import "fmt"

func firstUniqChar(s string) int {
	used := make([]int, 26)
	byts := []byte(s)
	for _, c := range byts {
		used[c-'a']++
	}
	for i, c := range byts {
		if used[c-'a'] == 1 {
			return i
		}
	}
	return -1
}

func main() {
	fmt.Println(firstUniqChar("leetcode"), 0)
	fmt.Println(firstUniqChar("loveleetcode"), 2)
}
