package main

import (
	"fmt"
)

func findCircleNum(isConnected [][]int) int {
	n := len(isConnected)
	visited := make([]int, n)
	ans := 0
	var dfs func(i int)
	dfs = func(i int) {
		for j := 0; j < n; j++ {
			if isConnected[i][j] == 1 && visited[j] == 0 {
				visited[j] = 1
				dfs(j)
			}
		}
	}
	for i := 0; i < n; i++ {
		if visited[i] == 0 {
			dfs(i)
			ans++
		}
	}
	return ans
}

func findCircleNum1(isConnected [][]int) int {
	n := len(isConnected)
	visited := make([]bool, n)
	ans := 0
	for i, v := range visited {
		if !v {
			ans++
			queue := []int{i}
			for len(queue) > 0 {
				c := queue[0]
				queue = queue[1:]
				visited[c] = true
				for to, conn := range isConnected[c] {
					if conn == 1 && !visited[to] {
						queue = append(queue, to)
					}
				}
			}
		}
	}

	return ans
}

func findCircleNum2(isConnected [][]int) int {
	n := len(isConnected)
	parent := make([]int, n)
	for i := range parent {
		parent[i] = i
	}
	var find func(int) int
	find = func(i int) int {
		if parent[i] != i {
			parent[i] = find(parent[i])
		}
		return parent[i]
	}
	union := func(from, to int) {
		parent[find(from)] = find(to)
	}
	for i, row := range isConnected {
		for j := i + 1; j < n; j++ {
			if row[j] == 1 {
				union(i, j)
			}
		}
	}
	ans := 0
	for i, p := range parent {
		if i == p {
			ans++
		}
	}
	return ans
}

func main() {
	fmt.Println(findCircleNum2([][]int{{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}}), 1)
	fmt.Println(findCircleNum2([][]int{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}), 2)
	fmt.Println(findCircleNum2([][]int{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}), 3)
}
