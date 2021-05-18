package main

import "fmt"

func countPrimes(n int) int {
	isprimes := make([]bool, n)
	for i := range isprimes {
		isprimes[i] = true
	}
	ans := 0
	for i := 2; i < n; i++ {
		if isprimes[i] {
			ans++
			if i*i < n {
				for j := i * i; j < n; j += i {
					isprimes[j] = false
				}
			}
		}
	}
	return ans
}

func countPrimes2(n int) int {
	primes := []int{}
	isprimes := make([]bool, n)
	for i := range isprimes {
		isprimes[i] = true
	}
	for i := 2; i < n; i++ {
		if isprimes[i] {
			primes = append(primes, i)
		}
		for _, v := range primes {
			if v*i < n {
				isprimes[v*i] = false
			}
			if i%v == 0 {
				break
			}
		}
	}
	return len(primes)
}

func main() {
	fmt.Printf("%d -> 4 \n", countPrimes2(10))
	fmt.Printf("%d -> 0 \n", countPrimes2(0))
	fmt.Printf("%d -> 0 \n", countPrimes2(1))
	fmt.Printf("%d -> 41537 \n", countPrimes(499979))
}
