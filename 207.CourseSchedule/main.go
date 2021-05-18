package main

import "fmt"

func canFinish(numCourses int, prerequisites [][]int) bool {
	//深度优先
	metrix := make([][]int, numCourses)
	visited := make([]int, numCourses)
	var fn func(n int) bool
	fn = func(n int) bool {
		visited[n] = 1 //正在遍历
		for _, v := range metrix[n] {
			if visited[v] == 0 {
				if !fn(v) {
					return false
				}
			} else if visited[v] == 1 {
				return false
			}
		}
		visited[n] = 2 //遍历完成
		return true
	}
	for _, v := range prerequisites {
		metrix[v[1]] = append(metrix[v[1]], v[0])
	}
	for i := 0; i < numCourses; i++ {
		if visited[i] == 0 {
			if !fn(i) {
				return false
			}
		}
	}
	return true
}

func canFinish2(numCourses int, prerequisites [][]int) bool {
	//广度优先
	metrix := make([][]int, numCourses)
	indeg := make([]int, numCourses)
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
	cnt := 0
	for len(q) > 0 {
		cnt++
		u := q[0]
		q = q[1:]
		for _, v := range metrix[u] {
			indeg[v]--
			if indeg[v] == 0 {
				q = append(q, v)
			}
		}
	}
	return cnt == numCourses
}

func main() {
	fmt.Printf("%v -> true \n", canFinish(2, [][]int{{1, 0}}))
	fmt.Printf("%v -> false \n", canFinish(2, [][]int{{1, 0}, {0, 1}}))
	fmt.Printf("%v -> true \n", canFinish2(2, [][]int{{1, 0}}))
	fmt.Printf("%v -> false \n", canFinish2(2, [][]int{{1, 0}, {0, 1}}))
}
