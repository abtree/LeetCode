package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
)

func nextGreaterElement(n int) int {
	bs := []byte(strconv.Itoa(n))
	l := len(bs)
	var dfs func(p int) bool
	dfs = func(p int) bool {
		if p < 0 {
			return false
		}
		for i := l - 1; i > p; i-- {
			if bs[p] < bs[i] {
				bs[p], bs[i] = bs[i], bs[p]
				ns := bs[p+1:]
				sort.Slice(ns, func(i, j int) bool {
					return ns[i] < ns[j]
				})
				return true
			}
		}
		return dfs(p - 1)
	}
	if dfs(l - 2) {
		ret, _ := strconv.Atoi(string(bs))
		if ret > math.MaxInt32 {
			return -1
		}
		return ret
	}
	return -1
}

func main() {
	fmt.Println(nextGreaterElement(2147483476), 2147483647)
	fmt.Println(nextGreaterElement(230241), 230412)
	fmt.Println(nextGreaterElement(13), 31)
	fmt.Println(nextGreaterElement(1234), 1243)
	fmt.Println(nextGreaterElement(12), 21)
	fmt.Println(nextGreaterElement(21), -1)
}
