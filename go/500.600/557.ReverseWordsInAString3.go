package main

import (
	"fmt"
)

func reverseWords(s string) string {
	byts := []byte(s)
	n := len(byts)
	p := 0
	for x := 0; x <= n; x++ {
		if x == n || byts[x] == ' ' {
			q := x - 1
			for p < q {
				byts[p], byts[q] = byts[q], byts[p]
				p++
				q--
			}
			p = x + 1
		}
	}
	return string(byts)
}

func main() {
	fmt.Println(reverseWords("Let's take LeetCode contest"), "s'teL ekat edoCteeL tsetnoc")
	fmt.Println(reverseWords("Mr Ding"), "rM gniD")
}
