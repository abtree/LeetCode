package main

import (
	"fmt"
	"sort"
)

func findLongestWord(s string, dictionary []string) string {
	cur := -1
	for i, t := range dictionary {
		if isSubstr(&t, &s) {
			if cur == -1 {
				cur = i
			} else if len(t) > len(dictionary[cur]) {
				cur = i
			} else if len(t) == len(dictionary[cur]) && t < dictionary[cur] {
				cur = i
			}
		}
	}
	if cur == -1 {
		return ""
	}
	return dictionary[cur]
}

func isSubstr(t, s *string) bool {
	nt, ns := len(*t), len(*s)
	if nt > ns {
		return false
	}
	pt, ps := 0, 0
	for pt < nt && ps < ns {
		if (*t)[pt] == (*s)[ps] {
			pt++
		}
		ps++
	}
	return pt == nt
}

func findLongestWord1(s string, dictionary []string) string {
	sort.Slice(dictionary, func(i, j int) bool {
		return len(dictionary[i]) > len(dictionary[j]) || (len(dictionary[i]) == len(dictionary[j]) && dictionary[i] < dictionary[j])
	})
	for _, t := range dictionary {
		if isSubstr(&t, &s) {
			return t
		}
	}
	return ""
}

func main() {
	fmt.Println(findLongestWord1("abpcplea", []string{"ale", "apple", "monkey", "plea"}), "apple")
	fmt.Println(findLongestWord1("abpcplea", []string{"a", "b", "c"}), "a")
}
