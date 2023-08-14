package main

import "fmt"

func numberOfBoomerangs(points [][]int) int {
	ret := 0
	for i, x := range points {
		dp := map[int]int{}
		for j, y := range points {
			if i != j {
				x := (x[0]-y[0])*(x[0]-y[0]) + (x[1]-y[1])*(x[1]-y[1])
				dp[x]++
			}
		}
		for _, v := range dp {
			if v > 1 {
				ret += multito(v) / multito(v-2)
			}
		}
	}
	return ret
}

func multito(x int) int {
	ret := 1
	for x > 1 {
		ret *= x
		x--
	}
	return ret
}

func main() {
	fmt.Println(numberOfBoomerangs([][]int{{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}}), 20)
	fmt.Println(numberOfBoomerangs([][]int{{0, 0}, {1, 0}, {2, 0}}), 2)
	fmt.Println(numberOfBoomerangs([][]int{{1, 1}, {2, 2}, {3, 3}}), 2)
	fmt.Println(numberOfBoomerangs([][]int{{0, 0}}), 0)
}
