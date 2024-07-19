package main

import (
	"fmt"
)

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func findLUSlength(strs []string) int {
	n := len(strs)
	ans := -1
	for i := 0; i < n; i++ {
		ns := len(strs[i])
		b := true
		for j := 0; j < n; j++ {
			if i == j {
				continue
			}
			if ns > len(strs[j]) {
				continue
			}
			if subStr(&strs[i], &strs[j]) {
				b = false
				break
			}
		}
		if b {
			ans = max(ans, ns)
		}
	}
	return ans
}

func subStr(s, t *string) bool {
	ps, pt := 0, 0
	ns, nt := len(*s), len(*t)
	for ps < ns && pt < nt {
		if (*s)[ps] == (*t)[pt] {
			ps++
		}
		pt++
	}
	return ps == ns
}

func main() {
	fmt.Println(findLUSlength([]string{"aba", "cdc", "eae"}), 3)
	fmt.Println(findLUSlength([]string{"aaa", "aaa", "aa"}), -1)
}
