package main

import (
	"fmt"
	"math/rand"
)

type Solution struct {
	m, n, total int
	dp          map[int]int
}

func Constructor(m int, n int) Solution {
	return Solution{
		m:     m,
		n:     n,
		total: m * n,
		dp:    map[int]int{},
	}
}

func (t *Solution) Flip() (ans []int) {
	x := rand.Intn(t.total)
	t.total--
	if v, ok := t.dp[x]; ok {
		ans = []int{v / t.n, v % t.n}
	} else {
		ans = []int{x / t.n, x % t.n}
	}
	if v, ok := t.dp[t.total]; ok {
		t.dp[x] = v
	} else {
		t.dp[x] = t.total
	}
	return
}

func (t *Solution) Reset() {
	t.dp = map[int]int{}
	t.total = t.m * t.n
}

func main() {
	cls := Constructor(3, 1)
	fmt.Println(cls.Flip())
	fmt.Println(cls.Flip())
	fmt.Println(cls.Flip())
	cls.Reset()
	fmt.Println(cls.Flip())
}
