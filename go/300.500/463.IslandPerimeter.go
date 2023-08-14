package main

import (
	"fmt"
)

func islandPerimeter(grid [][]int) int {
	m := len(grid)
	if m == 0 {
		return 0
	}
	n := len(grid[0])
	ret := 0
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 0 {
				continue
			}
			add := 4
			if i > 0 && grid[i-1][j] == 1 {
				add--
			}
			if i+1 < m && grid[i+1][j] == 1 {
				add--
			}
			if j > 0 && grid[i][j-1] == 1 {
				add--
			}
			if j+1 < n && grid[i][j+1] == 1 {
				add--
			}
			ret += add
		}
	}
	return ret
}

func main() {
	fmt.Println(islandPerimeter([][]int{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}}), 16)
	fmt.Println(islandPerimeter([][]int{{1}}), 4)
	fmt.Println(islandPerimeter([][]int{{1, 0}}), 4)
}
