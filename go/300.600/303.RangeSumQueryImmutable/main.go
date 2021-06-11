package main

import "fmt"

type NumArray struct {
	Nums []int
}

func Constructor(nums []int) NumArray {
	ret := NumArray{
		Nums: make([]int, len(nums)),
	}
	ret.Nums[0] = nums[0]
	for i := 1; i < len(nums); i++ {
		ret.Nums[i] = ret.Nums[i-1] + nums[i]
	}
	return ret
}

func (this *NumArray) SumRange(left int, right int) int {
	if left == 0 {
		return this.Nums[right]
	}
	return this.Nums[right] - this.Nums[left-1]
}

func main() {
	cls := Constructor([]int{-2, 0, 3, -5, 2, -1})
	fmt.Println(cls.SumRange(0, 2), 1)
	fmt.Println(cls.SumRange(2, 5), -1)
	fmt.Println(cls.SumRange(0, 5), -3)
}
