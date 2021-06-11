package main

import (
	"fmt"
	"strings"
)

func wordPattern(pattern string, s string) bool {
	srcs := strings.Fields(s)
	pats := []byte(pattern)
	if len(srcs) != len(pats) {
		return false
	}
	repeated := map[string]struct{}{}
	seen := map[byte]int{}
	for i, v := range pats {
		j, ok := seen[v]
		if !ok {
			if _, has := repeated[srcs[i]]; has {
				return false
			}
			seen[v] = i
			repeated[srcs[i]] = struct{}{}
		} else {
			if strings.Compare(srcs[i], srcs[j]) != 0 {
				return false
			}
		}
	}
	return true
}

func main() {
	fmt.Println(wordPattern("jquery", "jquery"), false)
	fmt.Println(wordPattern("aaa", "aa aa aa aa"), false)
	fmt.Println(wordPattern("abba", "dog cat cat dog"), true)
	fmt.Println(wordPattern("abba", "dog cat cat fish"), false)
	fmt.Println(wordPattern("aaaa", "dog cat cat dog"), false)
	fmt.Println(wordPattern("abba", "dog dog dog dog"), false)
}
