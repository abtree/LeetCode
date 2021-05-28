package main

import "fmt"

func computeArea(ax1 int, ay1 int, ax2 int, ay2 int, bx1 int, by1 int, bx2 int, by2 int) int {
	area := (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1)
	if ax1 > bx2 || ax2 < bx1 {
		return area
	}
	if ay1 > by2 || ay2 < by1 {
		return area
	}
	return area - (min(ax2, bx2)-max(ax1, bx1))*(min(ay2, by2)-max(ay1, by1))
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func main() {
	fmt.Println(computeArea(-3, 0, 3, 4, 0, -1, 9, 2), " -> 45")
	fmt.Println(computeArea(-2, -2, 2, 2, -2, -2, 2, 2), " -> 16")
}
