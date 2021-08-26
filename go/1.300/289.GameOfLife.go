package main

import "fmt"

func gameOfLife(board [][]int) {
	col := len(board)
	row := len(board[0])
	for i := 0; i < col; i++ {
		for j := 0; j < row; j++ {
			cnt := 0
			if i-1 >= 0 {
				if j-1 >= 0 && board[i-1][j-1] > 0 {
					cnt++
				}
				if board[i-1][j] > 0 {
					cnt++
				}
				if j+1 < row && board[i-1][j+1] > 0 {
					cnt++
				}
			}
			if i+1 < col {
				if j-1 >= 0 && board[i+1][j-1] > 0 {
					cnt++
				}
				if board[i+1][j] > 0 {
					cnt++
				}
				if j+1 < row && board[i+1][j+1] > 0 {
					cnt++
				}
			}
			if j-1 >= 0 && board[i][j-1] > 0 {
				cnt++
			}
			if j+1 < row && board[i][j+1] > 0 {
				cnt++
			}

			if board[i][j] == 0 {
				if cnt == 3 {
					board[i][j] = -1
				}
			} else {
				if cnt < 2 || cnt > 3 {
					board[i][j] = 2
				}
			}
		}
	}
	for i := 0; i < col; i++ {
		for j := 0; j < row; j++ {
			if board[i][j] == -1 {
				board[i][j] = 1
			} else if board[i][j] == 2 {
				board[i][j] = 0
			}
		}
	}
}

func main() {
	matrix := [][]int{
		{0, 1, 0},
		{0, 0, 1},
		{1, 1, 1},
		{0, 0, 0},
	}
	gameOfLife(matrix)
	fmt.Println(matrix)

	matrix1 := [][]int{
		{1, 1},
		{1, 0},
	}
	gameOfLife(matrix1)
	fmt.Println(matrix1)
}
