package main

import "fmt"

func findDuplicate(nums []int) int {
	start, end := 0, len(nums)
	for start < end {
		mid := (start + end) >> 1
		cnt := 0
		for _, v := range nums {
			if v <= mid {
				cnt++
			}
		}
		if cnt <= mid {
			start = mid + 1
		} else {
			end = mid
		}
	}
	return start
}

func findDuplicate2(nums []int) int {
	slow, fast := nums[0], nums[nums[0]]
	for slow != fast {
		slow = nums[slow]
		fast = nums[nums[fast]]
	}
	slow = 0
	for slow != fast {
		slow = nums[slow]
		fast = nums[fast]
	}
	return slow
}

func findDuplicate3(nums []int) int {
	n := len(nums) - 1
	bits := 31
	for (n >> bits) == 0 {
		bits--
	}
	ret := 0
	for bits >= 0 {
		x, y := 0, 0
		for i, v := range nums {
			if (v & (1 << bits)) > 0 {
				x++
			}
			if (i & (1 << bits)) > 0 {
				y++
			}
		}
		if x > y {
			ret |= (1 << bits)
		}
		bits--
	}
	return ret
}

func main() {
	fmt.Println(findDuplicate([]int{1, 3, 4, 2, 2}), findDuplicate2([]int{1, 3, 4, 2, 2}), findDuplicate3([]int{1, 3, 4, 2, 2}))
	fmt.Println(findDuplicate([]int{3, 1, 3, 4, 2}), findDuplicate2([]int{3, 1, 3, 4, 2}), findDuplicate3([]int{3, 1, 3, 4, 2}))
	fmt.Println(findDuplicate([]int{1, 1}), findDuplicate2([]int{1, 1}), findDuplicate3([]int{1, 1}))
	fmt.Println(findDuplicate([]int{1, 1, 2}), findDuplicate2([]int{1, 1, 2}), findDuplicate3([]int{1, 1, 2}))
}
