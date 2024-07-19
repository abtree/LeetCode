package main

import (
	"fmt"
	"math/rand"
	"sort"
)

type Solution struct {
	sum int
	pre []int
}

func Constructor(w []int) Solution {
	sum := 0
	pre := []int{}
	for _, x := range w {
		sum += x
		pre = append(pre, sum)
	}
	return Solution{
		sum: sum,
		pre: pre,
	}
}

func (t *Solution) PickIndex() int {
	x := rand.Intn(t.sum) + 1
	return sort.SearchInts(t.pre, x)
}

func main() {
	cls := Constructor([]int{1, 3})
	fmt.Println(cls.PickIndex())
	fmt.Println(cls.PickIndex())
	fmt.Println(cls.PickIndex())
	fmt.Println(cls.PickIndex())
	fmt.Println(cls.PickIndex())
}
