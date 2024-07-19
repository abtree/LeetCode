package main

import (
	"fmt"
	"unicode"
)

func detectCapitalUse(word string) bool {
	cap := 0
	for _, v := range word {
		if unicode.IsUpper(v) {
			cap++
		}
	}
	if cap == 0 || cap == len(word) {
		return true
	}
	if cap == 1 && unicode.IsUpper(rune(word[0])) {
		return true
	}
	return false
}

func detectCapitalUse1(word string) bool {
	n := len(word)
	if n >= 2 {
		b := unicode.IsUpper(rune(word[1]))
		if unicode.IsLower(rune(word[0])) && b {
			return false
		}
		for i := 2; i < n; i++ {
			if unicode.IsUpper(rune(word[i])) != b {
				return false
			}
		}
	}
	return true
}

func main() {
	fmt.Println(detectCapitalUse1("ggg"), true)
	fmt.Println(detectCapitalUse1("USA"), true)
	fmt.Println(detectCapitalUse1("FlaG"), false)
}
