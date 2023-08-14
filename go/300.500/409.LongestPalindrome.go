package main

import "fmt"

func longestPalindrome(s string) int {
	dp := map[byte]int{}
	byts := []byte(s)
	for _,c := range byts{
		dp[c]+=1
	}
	ret := 0;
	for _, v := range dp{
		if (v & 1) == 1{
			ret += v - 1
		}else{
			ret += v
		}
	}
	if ret < len(byts){
		ret += 1
	}
	return ret
}

func main() {
	fmt.Println(longestPalindrome("abccccdd"), 7)
	fmt.Println(longestPalindrome("a"), 1)
	fmt.Println(longestPalindrome("bb"), 2)
}