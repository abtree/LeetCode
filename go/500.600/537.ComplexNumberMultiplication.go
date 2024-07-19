package main

import (
	"fmt"
	"strconv"
	"strings"
)

func complexNumberMultiply(num1 string, num2 string) string {
	a1, b1 := split(&num1)
	a2, b2 := split(&num2)
	a := a1*a2 - b1*b2
	b := a1*b2 + a2*b1
	return fmt.Sprintf("%d+%di", a, b)
}

func split(num1 *string) (int, int) {
	strs := strings.FieldsFunc(*num1, func(r rune) bool {
		return r == '+'
	})
	a, _ := strconv.Atoi(strs[0])
	b, _ := strconv.Atoi(strings.TrimSuffix(strs[1], "i"))
	return a, b
}

func main() {
	fmt.Println(complexNumberMultiply("1+1i", "1+1i"), "0+2i")
	fmt.Println(complexNumberMultiply("1+-1i", "1+-1i"), "0+-2i")
}
