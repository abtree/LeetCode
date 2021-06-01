package main

import "fmt"

// hash_map 表计次法
func findRepeatedDnaSequences(s string) []string {
	ret := []string{}
	dp := make(map[string]int)
	size := len(s) - 9
	for i := 0; i < size; i++ {
		if cnt, ok := dp[s[i:i+10]]; ok && cnt == 1 {
			ret = append(ret, s[i:i+10])
		}
		dp[s[i:i+10]] += 1
	}
	return ret
}

func tobin(char uint8) int {
	switch char {
	case 'A':
		return 0
	case 'C':
		return 1
	case 'G':
		return 2
	case 'T':
		return 3
	default:
	}
	return 0
}

// 二进制计次法
func findRepeatedDnaSequences2(s string) []string {
	if len(s) < 11 {
		return []string{}
	}

	seen := map[int]int{}
	val := 0
	mask := (1 << 20) - 1
	ret := []string{}
	for i := 0; i < 10; i++ {
		val = (val << 2) | tobin(s[i])
	}
	seen[val] = 1
	for i := 10; i < len(s); i++ {
		val = ((val << 2) & mask) | tobin(s[i])
		if cnt, ok := seen[val]; ok {
			if cnt == 1 {
				ret = append(ret, s[i-9:i+1])
			} else {
				continue
			}
		}
		seen[val] += 1
	}
	return ret
}

func main() {
	ret := findRepeatedDnaSequences2("AAAAAAAAAAA")
	fmt.Println(ret)

	ret = findRepeatedDnaSequences2("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT")
	fmt.Println(ret)

	ret = findRepeatedDnaSequences2("AAAAAAAAAAAAA")
	fmt.Println(ret)
}
