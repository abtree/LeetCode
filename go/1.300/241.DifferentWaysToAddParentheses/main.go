package main

import "fmt"

func diffWaysToCompute(expression string) []int {
	byts := []byte(expression)
	n := len(byts)
	if n <= 0 {
		return []int{}
	}
	return subslice(byts)
}

func subslice(byts []byte) (ret []int) {
	for i, v := range byts {
		if v >= '0' && v <= '9' {
			continue
		}
		a := subslice(byts[:i])
		b := subslice(byts[i+1:])
		for _, x := range a {
			for _, y := range b {
				switch v {
				case '+':
					ret = append(ret, x+y)
				case '-':
					ret = append(ret, x-y)
				default:
					ret = append(ret, x*y)
				}
			}
		}
	}
	if len(ret) > 0 {
		return
	}
	num := 0
	for _, v := range byts {
		num = num*10 + int(v-'0')
	}
	ret = append(ret, num)
	return
}

func main() {
	fmt.Println(diffWaysToCompute("2-1-1"))
	fmt.Println(diffWaysToCompute("2*3-4*5"))
}
