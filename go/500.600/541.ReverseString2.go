package main

import (
	"fmt"
)

func reverseStr(s string, k int) string {
	byts := []byte(s)
	n := len(byts)
	p, q := 0, k
	for p < n {
		if q > n {
			q = n
		}
		m := q - 1
		for p < m {
			byts[p], byts[m] = byts[m], byts[p]
			p++
			m--
		}
		p = q + k
		q += 2 * k
	}
	return string(byts)
}

func main() {
	fmt.Println(reverseStr("abcdefg", 2), "bacdfeg")
	fmt.Println(reverseStr("abcd", 2), "bacd")
}
