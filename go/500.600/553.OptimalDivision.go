package main

import (
	"fmt"
	"strconv"
	"strings"
)

func optimalDivision(nums []int) string {
	n := len(nums)
	if n == 1 {
		return strconv.Itoa(nums[0])
	}
	if n == 2 {
		return fmt.Sprintf("%d/%d", nums[0], nums[1])
	}
	build := strings.Builder{}
	build.WriteString(strconv.Itoa(nums[0]))
	build.WriteString("/(")
	build.WriteString(strconv.Itoa(nums[1]))
	for _, x := range nums[2:] {
		build.WriteByte('/')
		build.WriteString(strconv.Itoa(x))
	}
	build.WriteByte(')')
	return build.String()
}

type node struct {
	minVal, maxVal float64
	minStr, maxStr string
}

func newNode() *node {
	return &node{
		minVal: 10000.0,
	}
}

func optimalDivision1(nums []int) string {
	n := len(nums)
	dp := make([][]*node, n)
	for i := range dp {
		dp[i] = make([]*node, n)
	}
	for i, v := range nums {
		if dp[i][i] == nil {
			dp[i][i] = newNode()
		}
		dp[i][i].minVal = float64(v)
		dp[i][i].maxVal = float64(v)
		dp[i][i].minStr = strconv.Itoa(v)
		dp[i][i].maxStr = strconv.Itoa(v)
	}
	for i := 1; i < n; i++ {
		for j := 0; j+i < n; j++ {
			for k := j; k < j+i; k++ {
				if dp[j][j+i] == nil {
					dp[j][j+i] = newNode()
				}
				v := dp[j][k].maxVal / dp[k+1][j+i].minVal
				if v > dp[j][j+i].maxVal {
					dp[j][j+i].maxVal = v
					if k+1 == j+i {
						dp[j][j+i].maxStr = fmt.Sprintf("%s/%s", dp[j][k].maxStr, dp[k+1][j+i].minStr)
					} else {
						dp[j][j+i].maxStr = fmt.Sprintf("%s/(%s)", dp[j][k].maxStr, dp[k+1][j+i].minStr)
					}
				}
				v = dp[j][k].minVal / dp[k+1][j+i].maxVal
				if v < dp[j][j+i].minVal {
					dp[j][j+i].minVal = v
					if k+1 == j+i {
						dp[j][j+i].minStr = fmt.Sprintf("%s/%s", dp[j][k].minStr, dp[k+1][j+i].maxStr)
					} else {
						dp[j][j+i].minStr = fmt.Sprintf("%s/(%s)", dp[j][k].minStr, dp[k+1][j+i].maxStr)
					}
				}
			}
		}
	}
	return dp[0][n-1].maxStr
}

func main() {
	fmt.Println(optimalDivision1([]int{1000, 100, 10, 2}), "1000/(100/10/2)")
	fmt.Println(optimalDivision1([]int{2, 3, 4}), "2/(3/4)")
}
