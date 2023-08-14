package main

import "fmt"

func longestIncreasingPath(matrix [][]int) int {
	m := len(matrix)
	n := len(matrix[0])
	dpl := make([]int, m*n)
	dp := make([][]int, m)
	for i := range dp {
		dp[i], dpl = dpl[:n], dpl[n:]
	}

	var longest func(i, j int) int
	longest = func(i, j int) int {
		if dp[i][j] > 0 {
			return dp[i][j]
		}
		dp[i][j] = 1
		if i-1 >= 0 && matrix[i-1][j] > matrix[i][j] {
			dp[i][j] = max(dp[i][j], longest(i-1, j)+1)
		}
		if i+1 < m && matrix[i+1][j] > matrix[i][j] {
			dp[i][j] = max(dp[i][j], longest(i+1, j)+1)
		}
		if j-1 >= 0 && matrix[i][j-1] > matrix[i][j] {
			dp[i][j] = max(dp[i][j], longest(i, j-1)+1)
		}
		if j+1 < n && matrix[i][j+1] > matrix[i][j] {
			dp[i][j] = max(dp[i][j], longest(i, j+1)+1)
		}
		return dp[i][j]
	}

	ret := 0
	for i, v := range matrix {
		for j := range v {
			ret = max(ret, longest(i, j))
		}
	}
	return ret
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func main() {
	fmt.Println(longestIncreasingPath([][]int{{9, 9, 4}, {6, 6, 8}, {2, 1, 1}}), 4)
	fmt.Println(longestIncreasingPath([][]int{{3, 4, 5}, {3, 2, 6}, {2, 2, 1}}), 4)
	fmt.Println(longestIncreasingPath([][]int{{3}}), 1)
	fmt.Println(longestIncreasingPath([][]int{{1, 2}}), 2)
}
