package main

import (
	"fmt"
)

func convertToBase7(num int) string {
	if num == 0 {
		return "0"
	}
	neg := num < 0
	if neg {
		num = -num
	}
	ret := []byte{}
	for num > 0 {
		ret = append(ret, byte(num%7)+'0')
		num /= 7
	}
	if neg {
		ret = append(ret, '-')
	}
	start, end := 0, len(ret)-1
	for start < end {
		ret[start], ret[end] = ret[end], ret[start]
		start++
		end--
	}
	return string(ret)
}

func main() {
	fmt.Println(convertToBase7(100), "202")
	fmt.Println(convertToBase7(-7), "-10")
}
