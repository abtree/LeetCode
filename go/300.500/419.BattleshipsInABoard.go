package main

import "fmt"

func countBattleships(board [][]byte) int {
	cnt := 0
	for i, v := range board {
		for j, c := range v {
			if c == '.' {
				continue
			}
			if i > 0 && board[i-1][j] == 'X' {
				continue
			}
			if j > 0 && board[i][j-1] == 'X' {
				continue
			}
			cnt++
		}
	}
	return cnt
}

func main() {
	fmt.Println(countBattleships([][]byte{{'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}}), 2)
	fmt.Println(countBattleships([][]byte{{'.'}}), 0)
}
