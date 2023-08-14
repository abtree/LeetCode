package main

import (
	"fmt"
	"math"
)

func isRectangleCover(rectangles [][]int) bool {
	key := func(x, y int) int{
		return x*1024+y
	}
	dp := map[int]int{}
	incr := func(rect []int){
		dp[key(rect[0], rect[1])]++
		dp[key(rect[0], rect[3])]++
		dp[key(rect[2], rect[1])]++
		dp[key(rect[2], rect[3])]++
	}
	area := func(rect []int)int{
		return int(math.Abs(float64(rect[2]-rect[0])*float64(rect[3]-rect[1])))
	}
	incr(rectangles[0])
	areas := area(rectangles[0])
	maxrect := rectangles[0]
	for i, x := range rectangles{
		if i == 0{
			continue
		}
		incr(x)
		if maxrect[0] > x[0]{
			maxrect[0] = x[0]
		}
		if maxrect[1] > x[1]{
			maxrect[1] = x[1]
		} 
		if maxrect[2] < x[2]{
			maxrect[2] = x[2]
		} 
		if maxrect[3] < x[3]{
			maxrect[3] = x[3]
		} 
		areas += area(x)
	}
	if area(maxrect) != areas{
		return false
	}
	incr(maxrect)
	for _, v := range dp{
		if v&1== 1{
			return false
		}
	}
	return true
}

func main() {
	fmt.Println(isRectangleCover([][]int{ {1, 1, 3, 3}, { 3,1,4,2 }, { 3,2,4,4 }, { 1,3,2,4 }, { 2,3,3,4 }}), true)
	fmt.Println(isRectangleCover([][]int{ {0, 0, 1, 1}, { 0,1,3,2 }, { 1,0,2,2 }}), false)
	fmt.Println(isRectangleCover([][]int{ {1, 1, 2, 3}, { 1,3,2,4 }, { 3,1,4,2 }, { 3,2,4,4 }}), false)
	fmt.Println(isRectangleCover([][]int{ {1, 1, 3, 3}, { 3,1,4,2 }, { 1,3,2,4 }, { 3,2,4,4 }}), false)
	fmt.Println(isRectangleCover([][]int{ {1, 1, 3, 3}, { 3,1,4,2 }, { 1,3,2,4 }, { 2,2,4,4 }}), false)
}