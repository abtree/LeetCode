package main

import "fmt"

func addDigits(num int) int {
	if num < 10 {
		return num
	}
	return (num-1)%9 + 1
}

func addDigits2(num int) int {
	for num > 10 {
		ret := 0
		for num > 0 {
			ret += num % 10
			num /= 10
		}
		num = ret
	}
	return num
}

func main() {
	fmt.Println(addDigits(38), 2)
	fmt.Println(addDigits2(38), 2)
}
