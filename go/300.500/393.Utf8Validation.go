package main

import "fmt"

func validUtf8(data []int) bool {
	c := 0;
	for _, x := range data{
		if c > 0{
			if count1s(x) != 1{
				return false;
			}
			c--
		}else{
			c = count1s(x)
			if c < 0{
				return false
			}
			if c == 1{
				return false
			}
			if c > 1{
				c--
			}
		}
	}
	return c == 0
}

func count1s(x int) int{
	if ((x>> 7)&1) == 0{
		return 0
	}
	if ((x>> 6)&1) == 0{
		return 1
	}
	if ((x>> 5)&1) == 0{
		return 2
	}
	if ((x>> 4)&1) == 0{
		return 3
	}
	if ((x>> 3)&1) == 0{
		return 4
	}
	return -1
}

func main() {
	fmt.Println(validUtf8([]int{197,130,1}), true)
	fmt.Println(validUtf8([]int{235,140,4}), false)
}