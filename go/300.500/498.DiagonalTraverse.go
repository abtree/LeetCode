package main

import (
	"fmt"
)

func findDiagonalOrder(mat [][]int) []int {
	ret := []int{}
	x, y, dx, dy, sx, sy := 0, 0, -1, 1, len(mat)-1, len(mat[0])-1
	change := func() {
		dx = -dx
		dy = -dy
	}
	for {
		ret = append(ret, mat[x][y])
		if x == sx && y == sy {
			break
		}
		if dx < 0 && x == 0 {
			if y == sy {
				x++
			} else {
				y++
			}
			change()
			continue
		}
		if dy < 0 && y == 0 {
			if x == sx {
				y++
			} else {
				x++
			}
			change()
			continue
		}
		if dx > 0 && x == sx {
			y++
			change()
			continue
		}
		if dy > 0 && y == sy {
			x++
			change()
			continue
		}
		x += dx
		y += dy
	}
	return ret
}

func findDiagonalOrder1(mat [][]int) []int {
	m, n := len(mat), len(mat[0])
	size := m + n - 1
	ret := []int{}
	for i := 0; i < size; i++ {
		if i&1 == 1 {
			x, y := 0, i
			if i >= n {
				x = i - n + 1
				y = n - 1
			}
			for x < m && y >= 0 {
				ret = append(ret, mat[x][y])
				x++
				y--
			}
		} else {
			x, y := i, 0
			if i >= m {
				x = m - 1
				y = i - m + 1
			}
			for x >= 0 && y < n {
				ret = append(ret, mat[x][y])
				x--
				y++
			}
		}
	}
	return ret
}

func main() {
	fmt.Println(findDiagonalOrder1([][]int{{1, 2}, {3, 4}}), "[1,2,3,4]")
	fmt.Println(findDiagonalOrder1([][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}), "[1,2,4,7,5,3,6,8,9]")
}
