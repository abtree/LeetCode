package main

import (
	"fmt"
	"math"
)

func kthSmallest(matrix [][]int, k int) int {
	dp := make([]int, len(matrix))
	ret := 0
	for ; k > 0; k-- {
		curr := 0
		ret = math.MaxInt32
		for i, v := range dp {
			if v < len(matrix[0]) && matrix[i][v] < ret {
				ret = matrix[i][v]
				curr = i
			}
		}
		dp[curr]++
	}
	return ret
}

func kthSmallest1(matrix [][]int, k int) int {
	left := matrix[0][0]
	right := matrix[len(matrix)-1][len(matrix[0])-1]
	for left < right {
		mid := left + (right-left)/2
		if count(matrix, mid) >= k {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}

func count(matrix [][]int, mid int) int {
	i := len(matrix) - 1
	j := 0
	num := 0
	for i >= 0 && j < len(matrix[0]) {
		if matrix[i][j] <= mid {
			num += i + 1
			j++
		} else {
			i--
		}
	}
	return num
}

func main() {
	fmt.Println(kthSmallest1([][]int{{-5, -4}, {-5, -4}}, 2))
	fmt.Println(kthSmallest([][]int{{1, 5, 9}, {10, 11, 13}, {12, 13, 15}}, 8), kthSmallest1([][]int{{1, 5, 9}, {10, 11, 13}, {12, 13, 15}}, 8), 13)
	fmt.Println(kthSmallest([][]int{{-5}}, 1), kthSmallest1([][]int{{-5}}, 1), -5)
	fmt.Println(kthSmallest([][]int{{1, 3, 5}, {6, 7, 12}, {11, 14, 14}}, 3), kthSmallest1([][]int{{1, 3, 5}, {6, 7, 12}, {11, 14, 14}}, 3), 5)
}
