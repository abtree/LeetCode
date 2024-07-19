package main

import (
	"fmt"
)

func checkRecord(s string) bool {
	as, ls := 0, 0
	for _, c := range s {
		if c == 'A' {
			as++
			if as > 1 {
				return false
			}
			ls = 0
		} else if c == 'L' {
			ls++
			if ls > 2 {
				return false
			}
		} else {
			ls = 0
		}
	}
	return true
}

func main() {
	fmt.Println(checkRecord("PPALLP"), true)
	fmt.Println(checkRecord("PPALLL"), false)
}
