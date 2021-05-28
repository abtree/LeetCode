package main

import "fmt"

func calculate(s string) int {
	sign := 1
	stack := []int{1}
	byts := []byte(s)
	n := len(byts)
	i := 0
	ret := 0
	for i < n {
		if byts[i] == ' ' {
			i++
		} else if byts[i] == '(' {
			stack = append(stack, sign)
			i++
		} else if byts[i] == ')' {
			stack = stack[:len(stack)-1]
			sign = stack[len(stack)-1]
			i++
		} else if byts[i] == '+' {
			i++
		} else if byts[i] == '-' {
			sign = -sign
			i++
		} else {
			num := 0
			for i < n && byts[i] >= '0' && byts[i] <= '9' {
				num = num*10 + int(byts[i]-'0')
				i++
			}
			ret += sign * num
			sign = stack[len(stack)-1]
		}
	}
	return ret
}

func main() {
	fmt.Println(calculate("(7)-(0)+(4)"), " -> 11")
	fmt.Println(calculate("1--1"), " -> 2")
	fmt.Println(calculate("1-(+1+1)"), " -> -1")
	fmt.Println(calculate("- (3 + (4 + 5))"), " -> -12")
	fmt.Println(calculate("1"), " -> 1")
	fmt.Println(calculate("48+ -48"), " -> 0")
	fmt.Println(calculate("(1+(4+5+2)-3)+(6+8)"), " -> 23")
	fmt.Println(calculate("1 + 1"), " -> 2")
	fmt.Println(calculate("2-1 + 2"), " -> 3")
}
