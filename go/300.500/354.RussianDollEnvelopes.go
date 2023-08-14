package main

import (
	"fmt"
	"sort"
)

func maxEnvelopes(envelopes [][]int) int {
	sort.Slice(envelopes, func(i, j int) bool {
		if envelopes[i][0] < envelopes[j][0] {
			return true
		}
		if envelopes[i][0] == envelopes[j][0] && envelopes[i][1] > envelopes[j][1] {
			return true
		}
		return false
	})

	dp := []int{}
	dp = append(dp, envelopes[0][1])
	size := len(envelopes)
	for i := 1; i < size; i++ {
		if envelopes[i][1] > dp[len(dp)-1] {
			dp = append(dp, envelopes[i][1])
		} else {
			for p, v := range dp {
				if v >= envelopes[i][1] {
					dp[p] = envelopes[i][1]
					break
				}
			}
		}
	}
	return len(dp)
}

func main() {
	fmt.Println(maxEnvelopes([][]int{{46, 89}, {50, 53}, {52, 68}, {72, 45}, {77, 81}}), 3)
	fmt.Println(maxEnvelopes([][]int{{2, 100}, {3, 200}, {4, 300}, {5, 500}, {5, 400}, {5, 250}, {6, 370}, {6, 360}, {7, 380}}), 5)
	fmt.Println(maxEnvelopes([][]int{{5, 4}, {6, 4}, {6, 7}, {2, 3}}), 3)
	fmt.Println(maxEnvelopes([][]int{{1, 1}, {1, 1}, {1, 1}}), 1)
}
