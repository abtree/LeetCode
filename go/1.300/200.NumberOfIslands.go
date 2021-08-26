package main

import (
	"fmt"
)

func numIslands(grid [][]byte) int {
	col := len(grid)
	if col == 0 {
		return 0
	}
	row := len(grid[0])
	ret := 0
	for i := 0; i < col; i++ {
		for j := 0; j < row; j++ {
			if grid[i][j] == '1' {
				round(grid, i, j)
				ret++
			}
		}
	}
	return ret
}

func round(grid [][]byte, i, j int) {
	if i < 0 || i >= len(grid) {
		return
	}
	if j < 0 || j >= len(grid[0]) {
		return
	}
	if grid[i][j] == '0' {
		return
	}
	grid[i][j] = '0'
	round(grid, i-1, j)
	round(grid, i+1, j)
	round(grid, i, j-1)
	round(grid, i, j+1)
}

func main() {
	grid := [][]byte{
		{'1', '1', '1'},
		{'0', '1', '0'},
		{'1', '1', '1'},
	}
	fmt.Printf(" %d -> 1 \n", numIslands(grid))

	grid = [][]byte{
		{'1', '1', '1', '1', '0'},
		{'1', '1', '0', '1', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '0', '0', '0'},
	}
	fmt.Printf(" %d -> 1 \n", numIslands(grid))

	grid = [][]byte{
		{'1', '1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'},
	}
	fmt.Printf(" %d -> 3 \n", numIslands(grid))
}
