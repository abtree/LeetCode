package main

import "fmt"

func calculate(s string) int {
	byts := []byte(s)
	n := len(byts)
	sign := 1
	op := byte(' ')
	nums := []int{}
	for i := 0; i < n; i++ {
		if byts[i] == ' ' {
			continue
		}
		if byts[i] == '+' {
			continue
		}
		if byts[i] == '-' {
			sign = -sign
			continue
		}
		if byts[i] == '*' || byts[i] == '/' {
			op = byts[i]
			continue
		}
		par := 0
		for i < n && byts[i] >= '0' && byts[i] <= '9' {
			par = par*10 + int(byts[i]-'0')
			i++
		}
		par *= sign
		sign = 1
		i--
		if op != ' ' {
			if op == '*' {
				nums[len(nums)-1] *= par
			} else {
				nums[len(nums)-1] /= par
			}
			op = ' '
		} else {
			nums = append(nums, par)
		}
	}
	ret := 0
	for _, v := range nums {
		ret += v
	}
	return ret
}

func main() {
	fmt.Println(calculate("1-2*-1"), "->3")
	fmt.Println(calculate("3+2*2"), "->7")
	fmt.Println(calculate("3/2"), "->1")
	fmt.Println(calculate("3+5/ 2 "), "->5")
}
