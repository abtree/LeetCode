package main

import (
	"fmt"
	"math"
	"math/bits"
	"strconv"
)

func smallestGoodBase(n string) string {
	nVal, _ := strconv.Atoi(n)
	mMax := bits.Len(uint(nVal)) - 1
	for m := mMax; m > 1; m-- {
		l := 2
		r := int(math.Pow(float64(nVal), 1/float64(m))) + 1
		for l < r {
			k := (l + r) / 2
			sum := 1
			for j := 0; j < m; j++ {
				sum = sum*k + 1
			}
			if sum == nVal {
				return strconv.Itoa(k)
			} else if sum < nVal {
				l = k + 1
			} else {
				r = k
			}
		}
	}
	return strconv.Itoa(nVal - 1)
}

func smallestGoodBase1(n string) string {
	nVal, _ := strconv.Atoi(n)
	mMax := bits.Len(uint(nVal)) - 1
	for m := mMax; m > 1; m-- {
		k := int(math.Pow(float64(nVal), 1/float64(m)))
		mul, sum := 1, 1
		for i := 0; i < m; i++ {
			mul *= k
			sum += mul
		}
		if sum == nVal {
			return strconv.Itoa(k)
		}
	}
	return strconv.Itoa(nVal - 1)
}

func main() {
	fmt.Println(smallestGoodBase("727004545306745403"), "727004545306745402")
	fmt.Println(smallestGoodBase("13"), "3")
	fmt.Println(smallestGoodBase1("4681"), "8")
	fmt.Println(smallestGoodBase1("1000000000000000000"), "999999999999999999")
}
