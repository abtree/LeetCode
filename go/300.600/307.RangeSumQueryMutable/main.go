package main

import (
	"fmt"
	"math"
)

//分块
type NumArray struct {
	Dat   []int
	Pre   []int
	Block int
}

func Constructor(nums []int) NumArray {
	ret := NumArray{
		Dat: nums,
	}
	ret.Block = int(math.Sqrt(float64(len(nums))))
	ret.Pre = make([]int, len(nums)/ret.Block+1)
	for i, v := range nums {
		ret.Pre[i/ret.Block] += v
	}
	return ret
}

func (this *NumArray) Update(index int, val int) {
	this.Pre[index/this.Block] += val - this.Dat[index]
	this.Dat[index] = val
}

func (this *NumArray) SumRange(left int, right int) int {
	l, r := left/this.Block, right/this.Block
	start, end := l*this.Block, min(len(this.Dat)-1, (r+1)*this.Block-1)
	ret := 0
	for l <= r {
		ret += this.Pre[l]
		l++
	}
	for start < left {
		ret -= this.Dat[start]
		start++
	}
	for end > right {
		ret -= this.Dat[end]
		end--
	}
	return ret
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

type NumArray1 struct {
	Size int
	Tree []int
}

func Constructor1(nums []int) NumArray1 {
	ret := NumArray1{
		Size: len(nums),
	}
	ret.Tree = make([]int, ret.Size*2)
	for i, j := ret.Size, 0; i < ret.Size*2; i++ {
		ret.Tree[i] = nums[j]
		j++
	}
	for i := ret.Size - 1; i > 0; i-- {
		ret.Tree[i] = ret.Tree[i*2] + ret.Tree[i*2+1]
	}
	return ret
}

func (this *NumArray1) Update(index int, val int) {
	index += this.Size
	this.Tree[index] = val
	for index > 1 {
		left, right := index, index
		if index%2 == 0 {
			right += 1
		} else {
			left -= 1
		}
		index /= 2
		this.Tree[index] = this.Tree[left] + this.Tree[right]
	}
}

func (this *NumArray1) SumRange(left int, right int) int {
	left += this.Size
	right += this.Size
	ret := 0
	for left <= right {
		if left%2 == 1 {
			ret += this.Tree[left]
			left++
		}
		if right%2 == 0 {
			ret += this.Tree[right]
			right--
		}
		left /= 2
		right /= 2
	}
	return ret
}

func main() {
	cls := Constructor1([]int{1, 3, 5})
	fmt.Println(cls.SumRange(0, 2), 9)
	cls.Update(1, 2)
	fmt.Println(cls.SumRange(0, 2), 8)
}
