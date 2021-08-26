package main

import "fmt"

func searchMatrix(matrix [][]int, target int) bool {
	row := len(matrix) - 1
	if row < 0 {
		return false
	}
	col, colmax := 0, len(matrix[0])
	for row >= 0 && col < colmax {
		if matrix[row][col] > target {
			row--
		} else if matrix[row][col] < target {
			col++
		} else {
			return true
		}
	}
	return false
}

func main() {
	matrix := [][]int{
		{1, 4, 7, 11, 15},
		{2, 5, 8, 12, 19},
		{3, 6, 9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30},
	}
	fmt.Println(searchMatrix(matrix, 5), true)
	fmt.Println(searchMatrix(matrix, 20), false)
}
