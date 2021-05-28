package main

import "fmt"

func getSkyline(buildings [][]int) [][]int {
	size := len(buildings)
	ret := [][]int{}
	if size == 0 {
		return ret
	}
	if size == 1 {
		ret = append(ret, []int{buildings[0][0], buildings[0][2]})
		ret = append(ret, []int{buildings[0][1], 0})
		return ret
	}
	left := getSkyline(buildings[:size/2])
	right := getSkyline(buildings[size/2:])
	return merge(left, right)
}

func merge(left, right [][]int) [][]int {
	nL, nR := len(left), len(right)
	pL, pR := 0, 0
	currY, leftY, rightY, maxY := 0, 0, 0, 0
	x := 0
	output := [][]int{}
	for (pL < nL) && (pR < nR) {
		if left[pL][0] < right[pR][0] {
			x = left[pL][0]
			leftY = left[pL][1]
			pL++
		} else {
			x = right[pR][0]
			rightY = right[pR][1]
			pR++
		}
		maxY = max(leftY, rightY)
		if currY != maxY {
			output = update(output, x, maxY)
			currY = maxY
		}
	}
	//处理剩余数据
	if pL < nL {
		output = tail(left, pL, nL, output, currY)
	} else {
		output = tail(right, pR, nR, output, currY)
	}
	return output
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func update(output [][]int, x, y int) [][]int {
	if len(output) == 0 || output[len(output)-1][0] != x {
		output = append(output, []int{x, y})
	} else {
		output[len(output)-1][1] = y
	}
	return output
}

func tail(skyline [][]int, p, n int, output [][]int, currY int) [][]int {
	for p < n {
		if currY != skyline[p][1] {
			output = update(output, skyline[p][0], skyline[p][1])
			currY = skyline[p][1]
		}
		p++
	}
	return output
}

func main() {
	fmt.Println(getSkyline([][]int{
		{2, 9, 10},
		{3, 7, 15},
		{5, 12, 12},
		{15, 20, 10},
		{19, 24, 8},
	}))
	fmt.Println(getSkyline([][]int{
		{0, 2, 3},
		{2, 5, 3},
	}))
}
