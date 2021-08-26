package main

import "fmt"

func removeDuplicateLetters(s string) string {
	byts := []byte(s)
	repeated := map[byte]int{}
	used := map[byte]bool{}
	for _, v := range byts {
		repeated[v] += 1
	}
	ret := make([]byte, 0, len(s))
	for _, v := range byts {
		if len(ret) == 0 {
			used[v] = true
			repeated[v] -= 1
			ret = append(ret, v)
			continue
		}
		if used[v] {
			repeated[v] -= 1
			continue
		}
		for len(ret) > 0 {
			c := ret[len(ret)-1]
			if c < v {
				break
			}
			if repeated[c] == 0 {
				break
			}
			used[c] = false
			ret = ret[:len(ret)-1]
		}
		used[v] = true
		repeated[v] -= 1
		ret = append(ret, v)
	}
	return string(ret)
}

func main() {
	fmt.Println(removeDuplicateLetters("abacb"), "abc")
	fmt.Println(removeDuplicateLetters("bcabc"), "abc")
	fmt.Println(removeDuplicateLetters("cbacdcbc"), "acdb")
}
