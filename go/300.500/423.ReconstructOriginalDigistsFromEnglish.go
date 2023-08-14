package main

import (
	"fmt"
	"strings"
)

func originalDigits(s string) string {
	dp := map[byte]int{}
	for _, c := range s {
		dp[byte(c)]++
	}
	ret := make([]int, 10)
	ret[0] = dp['z']
	ret[2] = dp['w']
	ret[4] = dp['u']
	ret[6] = dp['x']
	ret[8] = dp['g']
	ret[3] = dp['h'] - ret[8]
	ret[5] = dp['f'] - ret[4]
	ret[7] = dp['s'] - ret[6]
	ret[1] = dp['o'] - ret[0] - ret[2] - ret[4]
	ret[9] = dp['i'] - ret[5] - ret[6] - ret[8]
	sb := strings.Builder{}
	for i, x := range ret {
		for j := 0; j < x; j++ {
			sb.WriteByte(byte(i + '0'))
		}
	}
	return sb.String()
}

func main() {
	fmt.Println(originalDigits("owoztneoer"), "012")
	fmt.Println(originalDigits("fviefuro"), "45")
}
