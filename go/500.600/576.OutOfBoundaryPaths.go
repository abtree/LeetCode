package main

import "fmt"

const (
	MOD = 1000000007
)

func findPaths(m int, n int, maxMove int, startRow int, startColumn int) int {
	dirs := []struct{ x, y int }{{x: 0, y: -1}, {x: 0, y: 1}, {x: 1, y: 0}, {x: -1, y: 0}}
	outDirs := 0
	dp := make([][][]int, maxMove+1)
	for i := range dp {
		dp[i] = make([][]int, m)
		for j := range dp[i] {
			dp[i][j] = make([]int, n)
		}
	}
	dp[0][startRow][startColumn] = 1
	for i := 0; i < maxMove; i++ {
		for j := 0; j < m; j++ {
			for k := 0; k < n; k++ {
				start := dp[i][j][k]
				for _, v := range dirs {
					j1, k1 := j+v.x, k+v.y
					if j1 < 0 || j1 >= m || k1 < 0 || k1 >= n {
						outDirs = (outDirs + start) % MOD
					} else {
						dp[i+1][j1][k1] = (dp[i+1][j1][k1] + start) % MOD
					}
				}
			}
		}
	}
	return outDirs
}

func main() {
	fmt.Println(findPaths(2, 2, 2, 0, 0), 6)
	fmt.Println(findPaths(1, 3, 3, 0, 1), 12)
}
