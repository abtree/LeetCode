package main

import (
	"fmt"
	"sort"
)

func findContentChildren(g []int, s []int) int {
	sort.Slice(g, func(i, j int) bool {
		return g[i] < g[j]
	})
	sort.Slice(s, func(i, j int) bool {
		return s[i] < s[j]
	})
	i, j, r := 0, 0, 0
	for i < len(g) && j < len(s) {
		if s[j] >= g[i] {
			i++
			j++
			r++
		} else {
			j++
		}
	}
	return r
}

func main() {
	fmt.Println(findContentChildren([]int{10, 9, 8, 7}, []int{5, 6, 7, 8}), 2)
	fmt.Println(findContentChildren([]int{1, 2, 3, 4}, []int{1, 2}), 2)
}
