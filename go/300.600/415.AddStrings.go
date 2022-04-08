package main

import (
	"fmt"
)

func addStrings(num1 string, num2 string) string {
	m, n := len(num1), len(num2)
	size := m
	if size > n {
		size = n
	}
	add := 0
	ret := []byte{}
	for i := 1; i <= size; i++ {
		x := int(num1[m-i]-'0') + int(num2[n-i]-'0') + add
		if x >= 10 {
			x -= 10
			add = 1
		} else {
			add = 0
		}
		ret = append(ret, byte(x+'0'))
	}
	if m > size {
		for i := m - size - 1; i >= 0; i-- {
			if add > 0 {
				x := int(num1[i]-'0') + add
				if x >= 10 {
					x -= 10
					add = 1
				} else {
					add = 0
				}
				ret = append(ret, byte(x+'0'))
			} else {
				ret = append(ret, byte(num1[i]))
			}
		}
	}
	if n > size {
		for i := n - size - 1; i >= 0; i-- {
			if add > 0 {
				x := int(num2[i]-'0') + add
				if x >= 10 {
					x -= 10
					add = 1
				} else {
					add = 0
				}
				ret = append(ret, byte(x+'0'))
			} else {
				ret = append(ret, byte(num2[i]))
			}
		}
	}
	if add > 0 {
		ret = append(ret, '1')
	}
	n = len(ret)
	for i := 0; i < n/2; i++ {
		ret[i], ret[n-i-1] = ret[n-i-1], ret[i]
	}
	return string(ret)
}

func main() {
	fmt.Println(addStrings("6", "501"), "507")
	fmt.Println(addStrings("11", "123"), "134")
	fmt.Println(addStrings("456", "77"), "533")
	fmt.Println(addStrings("0", "0"), "0")
}
