package main

import "fmt"

type NumMatrix struct {
	Data [][]int
}

func Constructor(matrix [][]int) NumMatrix {
	col := len(matrix)
	row := len(matrix[0])
	ret := NumMatrix{
		Data: make([][]int, col),
	}
	for i, _ := range ret.Data {
		ret.Data[i] = make([]int, row)
	}
	ret.Data[0][0] = matrix[0][0]
	for i := 1; i < col; i++ {
		ret.Data[i][0] = ret.Data[i-1][0] + matrix[i][0]
	}
	for j := 1; j < row; j++ {
		ret.Data[0][j] = ret.Data[0][j-1] + matrix[0][j]
	}
	for i := 1; i < col; i++ {
		for j := 1; j < row; j++ {
			ret.Data[i][j] = ret.Data[i-1][j] + ret.Data[i][j-1] - ret.Data[i-1][j-1] + matrix[i][j]
		}
	}
	return ret
}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	if row1 == 0 && col1 == 0 {
		return this.Data[row2][col2]
	}
	if row1 == 0 {
		return this.Data[row2][col2] - this.Data[row2][col1-1]
	}
	if col1 == 0 {
		return this.Data[row2][col2] - this.Data[row1-1][col2]
	}
	return this.Data[row2][col2] - this.Data[row2][col1-1] - this.Data[row1-1][col2] + this.Data[row1-1][col1-1]
}

func main() {
	cls := Constructor([][]int{
		{3, 0, 1, 4, 2},
		{5, 6, 3, 2, 1},
		{1, 2, 0, 1, 5},
		{4, 1, 0, 1, 7},
		{1, 0, 3, 0, 5},
	})
	fmt.Println(cls.SumRegion(2, 1, 4, 3), 8)
	fmt.Println(cls.SumRegion(1, 1, 2, 2), 11)
	fmt.Println(cls.SumRegion(1, 2, 2, 4), 12)
}
