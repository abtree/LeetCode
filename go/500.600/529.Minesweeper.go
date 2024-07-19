package main

import (
	"fmt"
)

var (
	dirX = [8]int{0, 0, 1, -1, 1, 1, -1, -1}
	dirY = [8]int{1, -1, 0, 0, 1, -1, 1, -1}
)

func updateBoard(board [][]byte, click []int) [][]byte {
	if board[click[0]][click[1]] == 'M' {
		board[click[0]][click[1]] = 'X'
		return board
	}
	m, n := len(board), len(board[0])
	var bfs func(x, y int)
	bfs = func(x, y int) {
		cnt := 0
		for i := 0; i < 8; i++ {
			tx, ty := x+dirX[i], y+dirY[i]
			if tx >= 0 && tx < m && ty >= 0 && ty < n && board[tx][ty] == 'M' {
				cnt++
			}
		}
		if cnt > 0 {
			board[x][y] = byte(cnt) + '0'
			return
		}
		board[x][y] = 'B'
		for i := 0; i < 8; i++ {
			tx, ty := x+dirX[i], y+dirY[i]
			if tx >= 0 && tx < m && ty >= 0 && ty < n && board[tx][ty] == 'E' {
				bfs(tx, ty)
			}
		}
	}
	bfs(click[0], click[1])
	return board
}

func main() {
	board := [][]byte{
		{'E', 'E', 'E', 'E', 'E'},
		{'E', 'E', 'M', 'E', 'E'},
		{'E', 'E', 'E', 'E', 'E'},
		{'E', 'E', 'E', 'E', 'E'},
	}
	board = updateBoard(board, []int{3, 0})
	fmt.Println(board)
	fmt.Println(updateBoard(board, []int{1, 2}))
}
