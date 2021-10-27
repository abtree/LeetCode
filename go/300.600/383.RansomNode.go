package main

import "fmt"

func canConstruct(ransomNote string, magazine string) bool {
	byts := []byte(magazine)
	counts := make([]int, 26)
	for _, v := range byts {
		counts[v-'a'] += 1
	}
	byts = []byte(ransomNote)
	for _, v := range byts {
		if counts[v-'a'] <= 0 {
			return false
		}
		counts[v-'a'] -= 1
	}
	return true
}

func main() {
	fmt.Println(canConstruct("a", "b"), false)
	fmt.Println(canConstruct("aa", "ab"), false)
	fmt.Println(canConstruct("aa", "aab"), true)
}
