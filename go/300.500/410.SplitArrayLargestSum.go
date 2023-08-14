package main

import "fmt"

func splitArray(nums []int, m int) int {
	left := 0
	right := 0
	for _, x := range nums{
		right += x
		if x > left{
			left = x
		}
	}
	for left < right{
		mid := (left + right) / 2
		sum, cnt := 0, 1
		for _, x:= range nums{
			if sum + x > mid{
				cnt++
				sum = x
			}else{
				sum+=x
			}
		}
		if cnt <= m{
			right = mid
		}else{
			left = mid+1
		}
	}
	return left
}

func main() {
	fmt.Println(splitArray([]int{7,2,5,10,8}, 2), 18)
	fmt.Println(splitArray([]int{1,2,3,4,5}, 2), 9)
	fmt.Println(splitArray([]int{1,4,4}, 3), 4)
}