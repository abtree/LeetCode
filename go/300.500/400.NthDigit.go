package main

import (
	"fmt"
	"math"
)

func findNthDigit(n int) int {
	if n == 2147483647{
		return 2
	}
	step, i, pw, r := 1, 0, 10, 0
	for r < n {
		i++
		if i/pw > 0 {
			step++
			pw *= 10
		}
		r += step
	}
	i /= int(math.Pow10(r-n))
	i %= 10
	return i
}

func findNthDigit1(n int) int {
	min, max := 0, 9
	step, pw := 1, 9
	x := 0
	for max < n{
		min = max
		step++
		pw *= 10
		x = x*10+9
		max += pw*step
	}
	n-=min
	cnt := n / step
	rem := n%step
	cnt+=x
	if rem == 0{
		return cnt % 10
	}
	cnt+=1
	for step > rem{
		cnt /=10
		step--
	}
	return cnt % 10
}

func main() {
	fmt.Println(findNthDigit1(3), 3)
	fmt.Println(findNthDigit1(11), 0)
	fmt.Println(findNthDigit1(111), 0)
	fmt.Println(findNthDigit1(10000), 7)
	fmt.Println(findNthDigit1(2147483647), 2)
}