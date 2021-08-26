package main

import "fmt"

func maximalSquare(matrix [][]byte) int {
	col := len(matrix)
	if col == 0 {
		return 0
	}
	row := len(matrix[0])
	ret := 0
	dp := make([][]int, col)
	for i, _ := range dp {
		dp[i] = make([]int, row)
	}

	for i, v := range matrix {
		for j, c := range v {
			if i == 0 || j == 0 {
				if c == byte('1') {
					dp[i][j] = 1
					ret = max(ret, dp[i][j])
				} else {
					dp[i][j] = 0
				}
			} else if c == byte('1') {
				dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1
				ret = max(ret, dp[i][j])
			} else {
				dp[i][j] = 0
			}
		}
	}
	return ret * ret
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func main() {
	fmt.Println(maximalSquare([][]byte{
		{'1', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0'},
	}), " -> 4")

	fmt.Println(maximalSquare([][]byte{
		{'0', '1'},
	}), " -> 1")

	fmt.Println(maximalSquare([][]byte{
		{'0', '1'},
		{'1', '0'},
	}), " -> 1")

	fmt.Println(maximalSquare([][]byte{{'0'}}), " -> 0")
}
