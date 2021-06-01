package main

import "fmt"

var cycle = map[int]struct{}{
	4: {}, 16: {}, 37: {}, 58: {}, 89: {}, 145: {}, 42: {}, 20: {},
}

func isHappy(n int) bool {
	for n != 1 {
		if _, ok := cycle[n]; ok {
			return false
		}
		total := 0
		for n > 0 {
			total += (n % 10) * (n % 10)
			n /= 10
		}
		n = total
	}
	return true
}

func isHappy2(n int) bool {
	repeated := map[int]struct{}{}
	for n != 1 {
		repeated[n] = struct{}{}
		total := 0
		for n > 0 {
			total += (n % 10) * (n % 10)
			n /= 10
		}
		if _, ok := repeated[total]; ok {
			return false
		}
		n = total
	}
	return true
}

func main() {
	fmt.Printf("%v -> true \n", isHappy2(19))
	fmt.Printf("%v -> false \n", isHappy2(2))
}
