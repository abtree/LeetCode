package main

import (
	"fmt"
)

const (
	mod = 1e9 + 7
)

func checkRecord(n int) int {
	dp := make([][2][3]int, n+1)
	dp[0][0][0] = 1
	for i := 1; i <= n; i++ {
		//p
		for j := 0; j < 2; j++ {
			for k := 0; k < 3; k++ {
				dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][k]) % mod
			}
		}
		//a
		for k := 0; k < 3; k++ {
			dp[i][1][0] = (dp[i][1][0] + dp[i-1][0][k]) % mod
		}
		//l
		for j := 0; j < 2; j++ {
			for k := 1; k < 3; k++ {
				dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k-1]) % mod
			}
		}
	}
	sum := 0
	for j := 0; j < 2; j++ {
		for k := 0; k < 3; k++ {
			sum = (sum + dp[n][j][k]) % mod
		}
	}
	return sum
}

// 优化内存使用版本
func checkRecord1(n int) int {
	dp := [2][3]int{}
	dp[0][0] = 1
	for i := 1; i <= n; i++ {
		ndp := [2][3]int{}
		//p
		for j := 0; j < 2; j++ {
			for k := 0; k < 3; k++ {
				ndp[j][0] = (ndp[j][0] + dp[j][k]) % mod
			}
		}
		//a
		for k := 0; k < 3; k++ {
			ndp[1][0] = (ndp[1][0] + dp[0][k]) % mod
		}
		//l
		for j := 0; j < 2; j++ {
			for k := 1; k < 3; k++ {
				ndp[j][k] = (ndp[j][k] + dp[j][k-1]) % mod
			}
		}
		dp = ndp
	}
	sum := 0
	for j := 0; j < 2; j++ {
		for k := 0; k < 3; k++ {
			sum = (sum + dp[j][k]) % mod
		}
	}
	return sum
}

type matrix [6][6]int

func (a matrix) mul(b matrix) matrix {
	c := matrix{}
	for i, row := range a {
		for j := range b[0] {
			for k, v := range row {
				c[i][j] = (c[i][j] + v*b[k][j]) % mod
			}
		}
	}
	return c
}

func (a matrix) pow(n int) matrix {
	res := matrix{}
	for i := range res {
		res[i][i] = 1
	}
	for ; n > 0; n >>= 1 {
		if n&1 > 0 {
			res = res.mul(a)
		}
		a = a.mul(a)
	}
	return res
}

func checkRecord2(n int) int {
	m := matrix{
		{1, 1, 0, 1, 0, 0},
		{1, 0, 1, 1, 0, 0},
		{1, 0, 0, 1, 0, 0},
		{0, 0, 0, 1, 1, 0},
		{0, 0, 0, 1, 0, 1},
		{0, 0, 0, 1, 0, 0},
	}
	res := m.pow(n)
	ans := 0
	for _, v := range res[0] {
		ans = (ans + v) % mod
	}
	return ans
}

func main() {
	fmt.Println(checkRecord2(2), 8)
	fmt.Println(checkRecord2(1), 3)
	fmt.Println(checkRecord2(10101), 183236316)
}
