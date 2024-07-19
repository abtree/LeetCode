package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func findMinDifference(timePoints []string) int {
	n := len(timePoints)
	if n > 1440 {
		return 0
	}
	dp := []int{}
	for _, v := range timePoints {
		dp = append(dp, toi(&v))
	}
	sort.Ints(dp)

	ans := 1440
	for i := 1; i < n; i++ {
		ans = min(ans, dp[i]-dp[i-1])
	}
	ans = min(ans, 1440-dp[n-1]+dp[0])
	return ans
}

func toi(ts *string) int {
	strs := strings.Split(*ts, ":")
	h, _ := strconv.Atoi(strs[0])
	m, _ := strconv.Atoi(strs[1])
	return h*60 + m
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func main() {
	fmt.Println(findMinDifference([]string{"23:59", "00:00"}), 1)
	fmt.Println(findMinDifference([]string{"00:00", "23:59", "00:00"}), 0)
	fmt.Println(findMinDifference([]string{"00:00", "04:00", "22:00"}), 120)
}
