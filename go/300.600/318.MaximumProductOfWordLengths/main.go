package main

import "fmt"

func maxProduct(words []string) int {
	n := len(words)
	tmp := make([]int, n)
	for i, v := range words {
		power := 0
		for _, c := range v {
			power |= (1 << (c - 'a'))
		}
		tmp[i] = power
	}
	ret := 0
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			if (tmp[i] & tmp[j]) == 0 {
				ret = max(len(words[i])*len(words[j]), ret)
			}
		}
	}
	return ret
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func main() {
	fmt.Println(maxProduct([]string{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"}), 16)
	fmt.Println(maxProduct([]string{"a", "ab", "abc", "d", "cd", "bcd", "abcd"}), 4)
	fmt.Println(maxProduct([]string{"a", "aa", "aaa", "aaaa"}), 0)
}
