package main

import (
	"fmt"
	"math"
)

func poorPigs(buckets int, minutesToDie int, minutesToTest int) int {
	if buckets == 1 {
		return 0
	}
	c := make([][]int, buckets+1)
	for i := range c {
		c[i] = make([]int, buckets+1)
	}
	c[0][0] = 1

	turn := minutesToTest / minutesToDie
	f := make([][]int, buckets)
	for i := range f {
		f[i] = make([]int, turn+1)
	}
	for i := 0; i < buckets; i++ {
		c[i][0] = 1
		c[i][i] = 1
		f[i][0] = 1
	}
	for j := 0; j <= turn; j++ {
		f[0][j] = 1
	}
	for i := 1; i < buckets; i++ {
		for j := 1; j < i; j++ {
			c[i][j] = c[i-1][j-1] + c[i-1][j]
		}
		for j := 1; j <= turn; j++ {
			for k := 0; k <= i; k++ {
				f[i][j] += f[k][j-1] * c[i][k]
			}
		}
		if f[i][turn] >= buckets {
			return i
		}
	}
	return 0
}

func poorPigs1(buckets int, minutesToDie int, minutesToTest int) int {
	states := minutesToTest/minutesToDie + 1
	pigs := math.Ceil(math.Log(float64(buckets))/math.Log(float64(states)) - 1e-5)
	return int(pigs)
}

func main() {
	fmt.Println(poorPigs(1000, 15, 60), 5)
	fmt.Println(poorPigs(4, 15, 15), 2)
	fmt.Println(poorPigs(4, 15, 30), 2)

	fmt.Println(poorPigs1(1000, 15, 60), 5)
	fmt.Println(poorPigs1(4, 15, 15), 2)
	fmt.Println(poorPigs1(4, 15, 30), 2)
}
