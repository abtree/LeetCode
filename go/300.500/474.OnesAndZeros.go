package main

import "fmt"

func getZerosOnes(str *string) []int {
	zerosOnes := make([]int, 2)
	for _, c := range *str {
		zerosOnes[c-'0']++
	}
	return zerosOnes
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func findMaxForm(strs []string, m int, n int) int {
	dp := make([][][]int, len(strs)+1)
	for i := range dp {
		dp[i] = make([][]int, m+1)
		for j := range dp[i] {
			dp[i][j] = make([]int, n+1)
		}
	}
	for i, str := range strs {
		zerosOnes := getZerosOnes(&str)
		for j := 0; j <= m; j++ {
			for k := 0; k <= n; k++ {
				dp[i+1][j][k] = dp[i][j][k]
				if j >= zerosOnes[0] && k >= zerosOnes[1] {
					dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j-zerosOnes[0]][k-zerosOnes[1]]+1)
				}
			}
		}
	}
	return dp[len(strs)][m][n]
}

func findMaxForm1(strs []string, m int, n int) int {
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}
	for _, str := range strs {
		zeroOnes := getZerosOnes(&str)
		for i := m; i >= zeroOnes[0]; i-- {
			for j := n; j >= zeroOnes[1]; j-- {
				dp[i][j] = max(dp[i][j], dp[i-zeroOnes[0]][j-zeroOnes[1]]+1)
			}
		}
	}
	return dp[m][n]
}

func main() {
	fmt.Println(findMaxForm1([]string{"10", "0001", "111001", "1", "0"}, 5, 3), 4)
	fmt.Println(findMaxForm1([]string{"10", "0", "1"}, 1, 1), 2)
}
