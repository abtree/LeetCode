package main

import (
	"fmt"
	"math/rand"
	"time"
)

type Solution struct {
	Orinum  []int
	Randnum []int
}

func init() {
	rand.Seed(time.Now().UnixNano())
}

func Constructor(nums []int) Solution {
	ret := Solution{
		Orinum:  nums,
		Randnum: make([]int, len(nums)),
	}
	copy(ret.Randnum, nums)
	return ret
}

func (this *Solution) Reset() []int {
	return this.Orinum
}

func (this *Solution) Shuffle() []int {
	n := len(this.Randnum)
	for i := 0; i < n; i++ {
		p := rand.Intn(n-i) + i
		this.Randnum[i], this.Randnum[p] = this.Randnum[p], this.Randnum[i]
	}
	return this.Randnum
}

func main() {
	cls := Constructor([]int{1, 2, 3})
	fmt.Println(cls.Shuffle())
	fmt.Println(cls.Reset())
	fmt.Println(cls.Shuffle())
}
