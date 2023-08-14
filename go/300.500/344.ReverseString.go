package main

import "fmt"

func reverseString(s []byte) {
	b, e := 0, len(s)-1
	for b < e {
		s[b], s[e] = s[e], s[b]
		b++
		e--
	}
}

func main() {
	s := []byte{'h', 'e', 'l', 'l', 'o'}
	reverseString(s)
	fmt.Println(string(s))

	s = []byte{'H', 'a', 'n', 'n', 'a', 'h'}
	reverseString(s)
	fmt.Println(string(s))
}
