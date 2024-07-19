package main

import (
	"fmt"
)

type pair struct {
	i, j int
}

var dirs = [4][2]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}

func updateMatrix(mat [][]int) [][]int {
	m, n := len(mat), len(mat[0])
	dist := make([][]int, m)
	for i := range dist {
		dist[i] = make([]int, n)
	}
	seen := make([][]int, m)
	for i := range seen {
		seen[i] = make([]int, n)
	}
	queue := []*pair{}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if mat[i][j] == 0 {
				queue = append(queue, &pair{i, j})
				seen[i][j] = 1
			}
		}
	}
	for len(queue) > 0 {
		nq := []*pair{}
		for _, cur := range queue {
			for i := 0; i < 4; i++ {
				nx := cur.i + dirs[i][0]
				ny := cur.j + dirs[i][1]
				if nx >= 0 && nx < m && ny >= 0 && ny < n && seen[nx][ny] == 0 {
					dist[nx][ny] = dist[cur.i][cur.j] + 1
					seen[nx][ny] = 1
					nq = append(nq, &pair{nx, ny})
				}
			}
		}
		queue = nq
	}

	return dist
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func updateMatrix1(mat [][]int) [][]int {
	m, n := len(mat), len(mat[0])
	dist := make([][]int, m)
	for i := range dist {
		dist[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if mat[i][j] == 1 {
				dist[i][j] = m + n
			}
		}
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if i > 0 {
				dist[i][j] = min(dist[i][j], dist[i-1][j]+1)
			}
			if j > 0 {
				dist[i][j] = min(dist[i][j], dist[i][j-1]+1)
			}
		}
	}
	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			if i+1 < m {
				dist[i][j] = min(dist[i][j], dist[i+1][j]+1)
			}
			if j+1 < n {
				dist[i][j] = min(dist[i][j], dist[i][j+1]+1)
			}
		}
	}
	return dist
}

func main() {
	fmt.Println(updateMatrix([][]int{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}))
	fmt.Println(updateMatrix1([][]int{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}}))
}
