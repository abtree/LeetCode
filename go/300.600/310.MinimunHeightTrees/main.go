package main

import "fmt"

func findMinHeightTrees(n int, edges [][]int) []int {
	if n == 1 {
		return []int{0}
	}
	if n == 2 {
		return []int{0, 1}
	}
	deep := make([]int, n)
	graph := make([][]int, n)
	for _, v := range edges {
		deep[v[0]]++
		deep[v[1]]++
		graph[v[0]] = append(graph[v[0]], v[1])
		graph[v[1]] = append(graph[v[1]], v[0])
	}
	queue := make([]int, 0, n)
	for i, v := range deep {
		if v == 1 {
			queue = append(queue, i)
		}
	}
	for n > 2 {
		size := len(queue)
		n -= size
		for i := 0; i < size; i++ {
			c := queue[0]
			queue = queue[1:]
			for _, v := range graph[c] {
				deep[v]--
				if deep[v] == 1 {
					queue = append(queue, v)
				}
			}
		}
	}
	return queue
}

func main() {
	fmt.Println(findMinHeightTrees(4, [][]int{{1, 0}, {1, 2}, {1, 3}}))
	fmt.Println(findMinHeightTrees(6, [][]int{{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}}))
	fmt.Println(findMinHeightTrees(1, [][]int{}))
	fmt.Println(findMinHeightTrees(2, [][]int{{0, 1}}))
}
