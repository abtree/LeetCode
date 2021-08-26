package main

import (
	"fmt"
)

func findOrder(numCourses int, prerequisites [][]int) []int {
	metrix := make([][]int, numCourses)
	visited := make([]int, numCourses)
	var dfs func(int) bool
	ret := make([]int, 0, numCourses)

	dfs = func(u int) bool {
		visited[u] = 1
		for _, v := range metrix[u] {
			if visited[v] == 0 {
				if !dfs(v) {
					return false
				}
			} else if visited[v] == 1 {
				return false
			}
		}
		visited[u] = 2
		ret = append(ret, u)
		return true
	}

	for _, info := range prerequisites {
		metrix[info[1]] = append(metrix[info[1]], info[0])
	}

	for i := 0; i < numCourses; i++ {
		if visited[i] == 0 {
			if !dfs(i) {
				return []int{}
			}
		}
	}

	i := 0
	j := numCourses - 1
	for i < j {
		ret[i], ret[j] = ret[j], ret[i]
		i++
		j--
	}
	return ret
}

func findOrder2(numCourses int, prerequisites [][]int) []int {
	metrix := make([][]int, numCourses)
	indeg := make([]int, numCourses)
	ret := make([]int, 0, numCourses)

	for _, v := range prerequisites {
		metrix[v[1]] = append(metrix[v[1]], v[0])
		indeg[v[0]]++
	}
	q := []int{}
	for i, v := range indeg {
		if v == 0 {
			q = append(q, i)
		}
	}

	for len(q) > 0 {
		u := q[0]
		q = q[1:]
		ret = append(ret, u)
		for _, v := range metrix[u] {
			indeg[v]--
			if indeg[v] == 0 {
				q = append(q, v)
			}
		}
	}

	if len(ret) != numCourses {
		return []int{}
	}
	return ret
}

func main() {
	fmt.Println(findOrder(2, [][]int{{1, 0}}))
	fmt.Println(findOrder(4, [][]int{{1, 0}, {2, 0}, {3, 1}, {3, 2}}))
	fmt.Println(findOrder2(2, [][]int{{1, 0}}))
	fmt.Println(findOrder2(4, [][]int{{1, 0}, {2, 0}, {3, 1}, {3, 2}}))
}
