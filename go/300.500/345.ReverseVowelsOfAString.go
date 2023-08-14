package main

import "fmt"

func reverseVowels(s string) string {
	byts := []byte(s)
	b, e := 0, len(byts)-1
	for b < e {
		if !isVowel(byts[b]) {
			b++
			continue
		}
		if !isVowel(byts[e]) {
			e--
			continue
		}
		byts[b], byts[e] = byts[e], byts[b]
		b++
		e--
	}
	return string(byts)
}

func isVowel(c byte) bool {
	switch c {
	case 'a', 'e', 'i', 'u', 'o', 'A', 'E', 'I', 'O', 'U':
		return true
	default:
	}
	return false
}

func main() {
	fmt.Println(reverseVowels("hello"), "holle")
	fmt.Println(reverseVowels("leetcode"), "leotcede")
}
