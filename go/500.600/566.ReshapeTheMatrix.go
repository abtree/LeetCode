package main

import "fmt"

func matrixReshape(mat [][]int, r int, c int) [][]int {
	m, n := len(mat), len(mat[0])
	if m*n != r*c {
		return mat
	}
	ret := make([][]int, r)
	for i := range ret {
		ret[i] = make([]int, c)
	}
	i, j := 0, 0
	for _, x := range mat {
		for _, y := range x {
			ret[i][j] = y
			j++
			if j >= c {
				j = 0
				i++
			}
		}
	}
	return ret
}

func main() {
	fmt.Println(matrixReshape([][]int{{1, 2}, {3, 4}}, 1, 4))
	fmt.Println(matrixReshape([][]int{{1, 2}, {3, 4}}, 2, 4))
}
