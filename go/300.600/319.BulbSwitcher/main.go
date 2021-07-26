package main

import (
	"fmt"
	"math"
)

func bulbSwitch(n int) int {
	return int(math.Sqrt(float64(n)))
}

func main() {
	fmt.Println(bulbSwitch(3), 1)
	fmt.Println(bulbSwitch(0), 0)
	fmt.Println(bulbSwitch(1), 1)
}
