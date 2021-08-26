package main

import (
	"fmt"
	"strings"
)

func isValidSerialization(preorder string) bool {
	if preorder == "#" {
		return true
	}
	arr := strings.Split(preorder, ",")
	dp := []int{}
	pos, max := -1, -1
	for _, v := range arr {
		if v == "#" {
			if pos < 0 {
				return false
			}
			if dp[pos] > 1 {
				return false
			}
			dp[pos]++
			for pos > -1 && dp[pos] > 1 {
				pos--
			}
		} else {
			if pos > -1 {
				dp[pos]++
			} else if max > -1 {
				return false
			}
			pos++
			if pos <= max {
				dp[pos] = 0
			} else {
				max++
				dp = append(dp, 0)
			}
		}
	}
	return pos == -1
}

func isValidSerialization1(preorder string) bool {
	arr := strings.Split(preorder, ",")
	seat := 1
	for _, v := range arr {
		if seat <= 0 {
			return false
		}
		seat--
		if v != "#" {
			seat += 2
		}
	}
	return seat == 0
}

func main() {
	fmt.Println(isValidSerialization1("9,3,4,#,#,1,#,#,2,#,6,#,#"), true)
	fmt.Println(isValidSerialization1("#,7,6,9,#,#,#"), false)
	fmt.Println(isValidSerialization1("9,3,4,#,#,1,#,#,#,2,#,6,#,#"), false)
	fmt.Println(isValidSerialization1("1,#"), false)
	fmt.Println(isValidSerialization1("9,#,#,1"), false)
	fmt.Println(isValidSerialization1("#"), true)
}
