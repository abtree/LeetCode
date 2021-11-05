package main

import (
	"fmt"
	"math/rand"
	"time"
)

func init(){
	rand.Seed(time.Now().UnixNano())
}

type Solution struct {
	nums []int
}

func Constructor(nums []int) Solution {
	return Solution{ nums:nums }
}

func (this *Solution) Pick(target int) int {
	c, r := 0, 0
	for i, v := range this.nums{
		if v == target{
			c++
			if rand.Intn(c) == 0{
				r = i
			}
		}
	}
	return r
}

func main() {
	cls := Constructor([]int{1,2,3,3,3})
	fmt.Println(cls.Pick(3))
	fmt.Println(cls.Pick(3))
	fmt.Println(cls.Pick(3))
	fmt.Println(cls.Pick(3))
	fmt.Println(cls.Pick(1))
	fmt.Println(cls.Pick(2))
}