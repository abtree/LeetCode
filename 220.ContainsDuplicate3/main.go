package main

import (
	"fmt"
	"math"
	"sort"
)

type Node struct {
	val, index int
}

func containsNearbyAlmostDuplicate(nums []int, k int, t int) bool {
	tmp := make([]*Node, len(nums))
	for i, v := range nums {
		tmp[i] = &Node{
			val:   v,
			index: i,
		}
	}
	sort.Slice(tmp, func(i, j int) bool {
		return tmp[i].val < tmp[j].val
	})
	for i := 0; i < len(nums)-1; i++ {
		for j := i + 1; j < len(nums); j++ {
			if tmp[j].val-tmp[i].val > t {
				break
			}
			if abs(tmp[j].index-tmp[i].index) <= k {
				return true
			}
		}
	}
	return false
}

func abs(i int) int {
	if i < 0 {
		return -i
	}
	return i
}

func main() {
	fmt.Println(containsNearbyAlmostDuplicate([]int{math.MinInt32, math.MaxInt32}, 1, 1), "->false")
	fmt.Println(containsNearbyAlmostDuplicate([]int{1, 2, 1, 1}, 1, 0), "->true")
	fmt.Println(containsNearbyAlmostDuplicate([]int{1, 2, 3, 1}, 3, 0), "->true")
	fmt.Println(containsNearbyAlmostDuplicate([]int{1, 0, 1, 1}, 1, 2), "->true")
	fmt.Println(containsNearbyAlmostDuplicate([]int{1, 5, 9, 1, 5, 9}, 2, 3), "->false")
}
