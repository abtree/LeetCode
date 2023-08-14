package main

import (
	"fmt"
	"strings"
)

func countSegments(s string) int {
	strs := strings.Fields(s)
	return len(strs)
}

func main() {
	fmt.Println(countSegments("Hello, my name is John"), 5)
}
