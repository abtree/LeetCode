package main

import (
	"fmt"
)

func getMaxRepetitions(s1 string, n1 int, s2 string, n2 int) int {
	if n1 == 0 {
		return 0
	}
	s1cnt, s2cnt, index := 0, 0, 0
	recall := map[int][2]int{}
	pre_loop := [2]int{}
	in_loop := [2]int{}
	for {
		s1cnt++
		for _, ch := range s1 {
			if byte(ch) == s2[index] {
				index++
				if index == len(s2) {
					s2cnt++
					index = 0
				}
			}
		}
		if s1cnt == n1 {
			return s2cnt / n2
		}
		if v, ok := recall[index]; ok {
			pre_loop[0], pre_loop[1] = v[0], v[1]
			in_loop[0], in_loop[1] = s1cnt-v[0], s2cnt-v[1]
			break
		} else {
			recall[index] = [2]int{s1cnt, s2cnt}
		}
	}
	ans := pre_loop[1] + (n1-pre_loop[0])/in_loop[0]*in_loop[1]
	rest := (n1 - pre_loop[0]) % in_loop[0]
	for i := 0; i < rest; i++ {
		for _, ch := range s1 {
			if byte(ch) == s2[index] {
				index++
				if index == len(s2) {
					ans++
					index = 0
				}
			}
		}
	}
	return ans / n2
}

func main() {
	fmt.Println(getMaxRepetitions("acb", 4, "ab", 2), 2)
	fmt.Println(getMaxRepetitions("acb", 1, "acb", 1), 1)
}
