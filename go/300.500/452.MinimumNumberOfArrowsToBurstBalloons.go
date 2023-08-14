package main

import (
	"fmt"
	"sort"
)

func findMinArrowShots(points [][]int) int {
	if len(points) == 0 {
		return 0
	}
	sort.Slice(points, func(i, j int) bool {
		return points[i][1] < points[j][1]
	})
	pos := points[0][1]
	ans := 1
	for _, point := range points {
		if point[0] > pos {
			ans++
			pos = point[1]
		}
	}
	return ans
}

func main() {
	dp := [][]int{
		{3, 9}, {7, 12}, {3, 8}, {6, 8}, {9, 10}, {2, 9}, {0, 9}, {3, 9}, {0, 6}, {2, 8},
	}
	fmt.Println(findMinArrowShots(dp), 2)

	dp = [][]int{
		{10, 16}, {2, 8}, {1, 6}, {7, 12},
	}
	fmt.Println(findMinArrowShots(dp), 2)

	dp = [][]int{
		{1, 2}, {3, 4}, {5, 6}, {7, 8},
	}
	fmt.Println(findMinArrowShots(dp), 4)

	dp = [][]int{
		{1, 2}, {2, 3}, {3, 4}, {4, 5},
	}
	fmt.Println(findMinArrowShots(dp), 2)
}
