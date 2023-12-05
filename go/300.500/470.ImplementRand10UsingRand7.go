package main

import (
	"fmt"
	"math/rand"
)

func rand7() int {
	return rand.Intn(7) + 1
}

func rand10() int {
	for {
		row := rand7()
		col := rand7()
		idx := (row-1)*7 + col
		if idx <= 40 {
			return 1 + (idx-1)%10
		}
	}
}

func main() {
	arr := []int{}
	for i := 0; i < 100; i++ {
		arr = append(arr, rand10())
	}
	fmt.Println(arr)
}
