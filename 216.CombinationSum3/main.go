package main

import "fmt"

func combinationSum3(k int, n int) [][]int {
	ret := [][]int{}
	tmp := make([]int, 0, k)
	var combination func(k, p, sum int)
	combination = func(k, p, sum int) {
		for i := p + 1; i < 10; i++ {
			if k > 1 {
				sum += i
				if sum > n {
					sum -= i
					return
				}
				tmp = append(tmp, i)
				combination(k-1, i, sum)
				tmp = tmp[:len(tmp)-1]
				sum -= i
			} else {
				if sum+i == n {
					tmp = append(tmp, i)
					cpy := make([]int, len(tmp))
					copy(cpy, tmp)
					ret = append(ret, cpy)
					tmp = tmp[:len(tmp)-1]
					return
				}
			}
		}
	}
	combination(k, 0, 0)
	return ret
}

func main() {
	fmt.Println(combinationSum3(3, 7))
	fmt.Println(combinationSum3(3, 9))
}
