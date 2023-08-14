package main

import (
	"bytes"
	"fmt"
	"sort"
)

func frequencySort(s string) string {
	mp := map[byte]int{}
	for i := range s {
		mp[s[i]]++
	}
	type pair struct {
		c   byte
		cnt int
	}
	pairs := make([]*pair, 0, len(mp))
	for k, v := range mp {
		pairs = append(pairs, &pair{k, v})
	}
	sort.Slice(pairs, func(i, j int) bool {
		return pairs[i].cnt > pairs[j].cnt
	})
	ans := make([]byte, 0, len(s))
	for _, p := range pairs {
		ans = append(ans, bytes.Repeat([]byte{p.c}, p.cnt)...)
	}
	return string(ans)
}

func frequencySort1(s string) string {
	mp := map[byte]int{}
	maxf := 0
	for i := range s {
		mp[s[i]]++
		maxf = max(maxf, mp[s[i]])
	}
	buckets := make([][]byte, maxf+1)
	for c, cnt := range mp {
		buckets[cnt] = append(buckets[cnt], c)
	}
	ans := make([]byte, 0, len(s))
	for i := maxf; i > 0; i-- {
		for _, ch := range buckets[i] {
			ans = append(ans, bytes.Repeat([]byte{ch}, i)...)
		}
	}
	return string(ans)
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func main() {
	fmt.Println("tree", frequencySort("tree"))
	fmt.Println("cccaaa", frequencySort("cccaaa"))
	fmt.Println("Aabb", frequencySort("Aabb"))

	fmt.Println("tree", frequencySort1("tree"))
	fmt.Println("cccaaa", frequencySort1("cccaaa"))
	fmt.Println("Aabb", frequencySort1("Aabb"))
}
