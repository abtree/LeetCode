package main

import (
	"fmt"
	"math"
)

func numSquares(n int) int {
	dp := make([]int, n+1)
	for i := 1; i <= n; i++ {
		dp[i] = 4
	}
	x := int(math.Pow(float64(n), 0.5))
	sqs := make([]int, x)
	for i := 1; i <= x; i++ {
		sqs[i-1] = i * i
	}
	for i := 1; i <= n; i++ {
		for j := 0; j < x; j++ {
			if i < sqs[j] {
				break
			}
			dp[i] = min(dp[i], dp[i-sqs[j]]+1)
		}
	}
	return dp[n]
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func numSquares2(n int) int {
	sqs := map[int]struct{}{}
	x := int(math.Pow(float64(n), 0.5))
	for i := 1; i <= x; i++ {
		sqs[i*i] = struct{}{}
	}
	count := 1
	for count < 5 {
		if isDividedBy(n, count, sqs) {
			return count
		}
		count++
	}
	return count
}

func isDividedBy(n, count int, sqs map[int]struct{}) bool {
	if count == 1 {
		if _, ok := sqs[n]; ok {
			return true
		}
		return false
	}
	for k, _ := range sqs {
		if isDividedBy(n-k, count-1, sqs) {
			return true
		}
	}
	return false
}

func numSquares3(n int) int {
	x := int(math.Pow(float64(n), 0.5))
	sqs := make([]int, x)
	for i := 1; i <= x; i++ {
		sqs[i-1] = i * i
	}
	q := []int{}
	q = append(q, n)
	lv := 0
	for len(q) > 0 {
		lv++
		size := len(q)
		for i := 0; i < size; i++ {
			c := q[0]
			q = q[1:]
			for j := 0; j < x; j++ {
				if c == sqs[j] {
					return lv
				} else if c < sqs[j] {
					break
				} else {
					q = append(q, c-sqs[j])
				}
			}
		}
	}
	return lv
}

func numSquares4(n int) int {
	x := n
	for x%4 == 0 {
		x /= 4
	}
	if x%8 == 7 {
		return 4
	}
	x = int(math.Pow(float64(n), 0.5))
	if x*x == n {
		return 1
	}
	sqs := make([]int, x)
	for i := 1; i <= x; i++ {
		sqs[i-1] = i * i
	}
	for i := 0; i < x; i++ {
		for j := i; j < x; j++ {
			if sqs[i]+sqs[j] == n {
				return 2
			} else if sqs[i]+sqs[j] > n {
				break
			}
		}
	}
	return 3
}

func main() {
	fmt.Println(numSquares4(2), 2)
	fmt.Println(numSquares4(1), 1)
	fmt.Println(numSquares4(12), 3)
	fmt.Println(numSquares4(13), 2)
	fmt.Println(numSquares4(999), 4)
}
