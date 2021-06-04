package main

import "sort"

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	src := map[rune]int{}
	dst := map[rune]int{}
	for _, v := range s {
		src[v]++
	}
	for _, v := range t {
		dst[v]++
	}
	for k, v := range src {
		if v1, ok := dst[k]; !ok || v != v1 {
			return false
		}
	}
	return true
}

func isAnagram2(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	src := []byte(s)
	dsc := []byte(t)
	sort.Slice(src, func(i, j int) bool {
		return src[i] < src[j]
	})
	sort.Slice(dsc, func(i, j int) bool {
		return dsc[i] < dsc[j]
	})
	for i, v := range src {
		if dsc[i] != v {
			return false
		}
	}
	return true
}

func main() {

}
