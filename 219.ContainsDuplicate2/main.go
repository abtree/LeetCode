package main

import "fmt"

func containsNearbyDuplicate(nums []int, k int) bool {
	kset := map[int]struct{}{}
	for i, v := range nums {
		if _, ok := kset[v]; ok {
			return true
		}
		kset[v] = struct{}{}
		if len(kset) > k {
			delete(kset, nums[i-k])
		}
	}
	return false
}

func main() {
	fmt.Println(containsNearbyDuplicate([]int{99, 99}, 2), "->true")
	fmt.Println(containsNearbyDuplicate([]int{1, 2, 3, 1}, 3), "->true")
	fmt.Println(containsNearbyDuplicate([]int{1, 0, 1, 1}, 1), "->true")
	fmt.Println(containsNearbyDuplicate([]int{1, 2, 3, 1, 2, 3}, 2), "->false")
}
