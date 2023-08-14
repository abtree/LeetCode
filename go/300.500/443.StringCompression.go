package main

import (
	"fmt"
	"strconv"
)

func compress(chars []byte) int {
	n := len(chars)
	p := 0
	cur := chars[0]
	cnt := 1
	for i := 1; i < n; i++ {
		if chars[i] == cur {
			cnt++
		} else {
			chars[p] = cur
			p++
			if cnt > 1 {
				s := strconv.Itoa(cnt)
				for i := range s {
					chars[p] = s[i]
					p++
				}
				cnt = 1
			}
			cur = chars[i]
		}
	}
	chars[p] = cur
	p++
	if cnt > 1 {
		s := strconv.Itoa(cnt)
		for i := range s {
			chars[p] = s[i]
			p++
		}
	}
	return p
}

func print(dat []byte, len int) {
	fmt.Printf("len: %d, %s \n", len, dat[:len])
}

func main() {
	dat := []byte{'a', 'a', 'b', 'b', 'c', 'c', 'c'}
	len := compress(dat)
	print(dat, len)

	dat = []byte{'a'}
	len = compress(dat)
	print(dat, len)

	dat = []byte{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'}
	len = compress(dat)
	print(dat, len)
}
