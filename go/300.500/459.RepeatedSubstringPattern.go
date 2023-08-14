package main

import (
	"fmt"
	"strings"
)

func repeatedSubstringPattern(s string) bool {
	s1 := s[1:]
	s2 := s1 + s
	p := strings.Index(s2, s)
	return p != len(s)-1
}

func repeatedSubstringPattern1(s string) bool {
	n := len(s)
	for i := 0; i < n/2; i++ {
		if n%(i+1) != 0 {
			continue
		}
		p := i + 1
		f := true
		for p < n {
			for j := 0; j <= i; j++ {
				if s[j] != s[p] {
					f = false
					break
				}
				p++
			}
			if !f {
				break
			}
		}
		if f {
			return true
		}
	}
	return false
}

func repeatedSubstringPattern2(s string) bool {
	return kmp(s+s, s)
}

func kmp(query, pattern string) bool {
	n, m := len(query), len(pattern)
	fail := make([]int, m)
	for i := 0; i < m; i++ {
		fail[i] = -1
	}
	for i := 1; i < m; i++ {
		j := fail[i-1]
		for j != -1 && pattern[j+1] != pattern[i] {
			j = fail[j]
		}
		if pattern[j+1] == pattern[i] {
			fail[i] = j + 1
		}
	}
	match := -1
	for i := 1; i < n-1; i++ {
		for match != -1 && pattern[match+1] != query[i] {
			match = fail[match]
		}
		if pattern[match+1] == query[i] {
			match++
			if match == m-1 {
				return true
			}
		}
	}
	return false
}

func repeatedSubstringPattern3(s string) bool {
	return kmp1(s)
}

func kmp1(pattern string) bool {
	n := len(pattern)
	fail := make([]int, n)
	for i := 0; i < n; i++ {
		fail[i] = -1
	}
	for i := 1; i < n; i++ {
		j := fail[i-1]
		for j != -1 && pattern[j+1] != pattern[i] {
			j = fail[j]
		}
		if pattern[j+1] == pattern[i] {
			fail[i] = j + 1
		}
	}
	return fail[n-1] != -1 && n%(n-fail[n-1]-1) == 0
}

func main() {
	fmt.Println(repeatedSubstringPattern("abab"), true)
	fmt.Println(repeatedSubstringPattern("aba"), false)
	fmt.Println(repeatedSubstringPattern("abcabcabcabc"), true)
}
