package main

import "fmt"

func canCross(stones []int) bool {
	//带记忆的递归
	if len(stones) == 0 {
		return true
	}
	dp := map[int]map[int]bool{}
	for _, x := range stones {
		dp[x] = map[int]bool{}
	}
	end := stones[len(stones)-1]
	var dfCross func(pos, min, max int) bool
	dfCross = func(pos, min, max int) bool {
		if pos == end {
			return true
		}
		if mp, ok := dp[pos]; ok {
			for max >= min {
				if b, o := mp[max]; o {
					if b {
						return true
					}
				} else {
					mp[max] = dfCross(pos+max, fmax(1, max-1), max+1)
					if mp[max] {
						return true
					}
				}
				max--
			}
		}
		return false
	}
	return dfCross(0, 1, 1)
}

func fmax(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func canCross2(stones []int) bool {
	//动态规划
	n := len(stones)
	for i := 1; i< n;i++{
		if stones[i] - stones[i-1] > i{
			return false
		}
	}
	dp := make([][]bool, n)
	for i := range dp{
		dp[i] = make([]bool, n)
	}
	dp[0][0] = true
	for i := 1;i<n;i++{
		for j:=i-1;j>=0;j--{
			k := stones[i] - stones[j]
			if k > j+1{
				break
			}
			dp[i][k] = dp[j][k-1] || dp[j][k] || dp[j][k+1]
			if i == n-1 && dp[i][k]{
				return true
			}
		}
	}
	return false
}

func main() {
	fmt.Println(canCross2([]int{0,1,3,6,7}), false)
	fmt.Println(canCross2([]int{0, 2147483647}), false)
	fmt.Println(canCross2([]int{0, 1, 3, 5, 6, 8, 12, 17}), true)
	fmt.Println(canCross2([]int{0,1,2,3,4,8,9,11}), false)
}