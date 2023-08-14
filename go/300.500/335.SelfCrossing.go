package main

import "fmt"

func isSelfCrossing(distance []int) bool {
	for i := range distance {
		if i >= 3 && distance[i-3] >= distance[i-1] && distance[i] >= distance[i-2] {
			return true
		} else if i >= 4 && distance[i-1] == distance[i-3] && distance[i-2] <= (distance[i]+distance[i-4]) {
			return true
		} else if i >= 5 && distance[i-3] >= distance[i-1] && distance[i-3] >= distance[i-5] && distance[i-3] <= (distance[i-1]+distance[i-5]) && distance[i-4] <= distance[i-2] && (distance[i-4]+distance[i]) >= distance[i-2] {
			return true
		}
	}
	return false
}

func isSelfCrossing1(distance []int) bool {
	dist := make([]int, 4, len(distance)+4)
	dist = append(dist, distance...)
	n := len(dist)
	i := 4
	for i < n && dist[i] > dist[i-2] {
		i++
	}
	if i == n {
		return false
	}
	if dist[i] >= dist[i-2]-dist[i-4] {
		dist[i-1] -= dist[i-3]
	}
	i++
	for i < n && dist[i] < dist[i-2] {
		i++
	}
	return i != n
}

func main() {
	fmt.Println(isSelfCrossing1([]int{1, 1, 2, 2, 1, 1}), true)
	fmt.Println(isSelfCrossing1([]int{1, 1, 2, 3, 3, 3, 1}), true)
	fmt.Println(isSelfCrossing1([]int{1, 1, 2, 1, 1}), true)
	fmt.Println(isSelfCrossing1([]int{2, 1, 1, 2}), true)
	fmt.Println(isSelfCrossing1([]int{1, 2, 3, 4}), false)
	fmt.Println(isSelfCrossing1([]int{1, 1, 1, 1}), true)
	fmt.Println(isSelfCrossing1([]int{1, 4, 3, 2, 5}), true)
}
