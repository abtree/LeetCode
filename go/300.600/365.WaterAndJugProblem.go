package main

import (
	"fmt"
)

func canMeasureWater(jug1Capacity int, jug2Capacity int, targetCapacity int) bool {
	if targetCapacity == jug1Capacity || targetCapacity == jug2Capacity || targetCapacity == jug1Capacity+jug2Capacity {
		return true
	}
	big, small := max(jug1Capacity, jug2Capacity), min(jug1Capacity, jug2Capacity)
	flags := map[int]bool{}
	x := big
	for x != targetCapacity {
		if x < small {
			if x+big == targetCapacity {
				return true
			}
			if v, ok := flags[x]; ok && v {
				return false
			}
			flags[x] = true
			x = big - small + x
		} else {
			x -= small
			if x == targetCapacity {
				return true
			}
		}
	}
	return true
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func canMeasureWater1(jug1Capacity int, jug2Capacity int, targetCapacity int) bool {
	if jug1Capacity+jug2Capacity < targetCapacity {
		return false
	}
	if jug1Capacity == 0 || jug2Capacity == 0 {
		return targetCapacity == 0 || jug1Capacity+jug2Capacity == targetCapacity
	}
	return targetCapacity%gcd(jug1Capacity, jug2Capacity) == 0
}

func gcd(a, b int) int {
	r := 0
	for b > 0 {
		r = a % b
		a = b
		b = r
	}
	return a
}

func main() {
	fmt.Println(canMeasureWater1(6, 9, 1), false)
	fmt.Println(canMeasureWater1(3, 5, 4), true)
	fmt.Println(canMeasureWater1(2, 6, 5), false)
	fmt.Println(canMeasureWater1(18, 7, 6), true)
	fmt.Println(canMeasureWater1(1, 2, 3), true)
}
