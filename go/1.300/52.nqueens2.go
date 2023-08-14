package main

import "fmt"

func totalNQueens(n int) (ans int) {
	cols := make([]bool, n)
	left := make([]bool, 2*n-1)
	right := make([]bool, 2*n-1)

	var backtrack func(int)
	backtrack = func(row int) {
		if row == n {
			ans++
			return
		}
		for col, has := range cols {
			d1, d2 := row+n-1-col, row+col
			if has || left[d1] || right[d2] {
				continue
			}
			cols[col] = true
			left[d1] = true
			right[d2] = true
			backtrack(row + 1)
			cols[col] = false
			left[d1] = false
			right[d2] = false
		}
	}
	backtrack(0)
	return
}

func totalNQueens2(n int) (ans int) {
	var solve func(row, cols, left, right int)
	solve = func(row, cols, left, right int) {
		if row == n {
			ans++
			return
		}
		available := (1<<n - 1) &^ (cols | left | right)
		for available > 0 {
			pos := available & -available
			solve(row+1, cols|pos, (left|pos)<<1, (right|pos)>>1)
			available &^= pos
		}
	}
	solve(0, 0, 0, 0)
	return
}

func main() {
	fmt.Println(totalNQueens(4))
	fmt.Println(totalNQueens(1))

	fmt.Println(totalNQueens2(4))
	fmt.Println(totalNQueens2(1))
}
