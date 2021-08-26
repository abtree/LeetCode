package main

import (
	"fmt"
	"strings"
)

var (
	Less20 = []string{
		"Zero", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ",
		"Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen ",
	}
	Tens = []string{
		"Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety ",
	}
	Tris = []string{
		"Billion ", "Million ", "Thousand ",
	}
)

func numberToWords(num int) string {
	if num == 0 {
		return Less20[0]
	}
	div := int(1e9)
	//ret := bytes.NewBuffer([]byte{})
	ret := &strings.Builder{}
	for i := 0; i < 3; i++ {
		if num >= div {
			trinums(num/div, ret)
			ret.WriteString(Tris[i])
			num %= div
		}
		div /= int(1e3)
	}
	if num > 0 {
		trinums(num, ret)
	}
	return strings.TrimSuffix(ret.String(), " ")
	//byts := ret.Bytes()
	//return string(byts[:len(byts)-1])
}

func trinums(num int, ret *strings.Builder) {
	tail := num % 100
	num /= 100
	if num > 0 {
		ret.WriteString(Less20[num])
		ret.WriteString("Hundred ")
	}
	if tail == 0 {
		return
	}
	if tail < 20 {
		ret.WriteString(Less20[tail])
	} else {
		num = tail / 10
		tail %= 10
		ret.WriteString(Tens[num-2])
		if tail > 0 {
			ret.WriteString(Less20[tail])
		}
	}
}

func main() {
	fmt.Println(0, numberToWords(0))
	fmt.Println(123, numberToWords(123))
	fmt.Println(12345, numberToWords(12345))
	fmt.Println(1234567, numberToWords(1234567))
	fmt.Println(1234567891, numberToWords(1234567891))
}
