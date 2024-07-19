package main

import (
	"fmt"
	"unicode"
)

func licenseKeyFormatting(s string, k int) string {
	ans := []byte{}
	for i, cnt := len(s)-1, 0; i >= 0; i-- {
		if s[i] != '-' {
			ans = append(ans, byte(unicode.ToUpper(rune(s[i]))))
			cnt++
			if cnt == k {
				ans = append(ans, '-')
				cnt = 0
			}
		}
	}
	if len(ans) > 0 && ans[len(ans)-1] == '-' {
		ans = ans[:len(ans)-1]
	}
	for i, n := 0, len(ans); i < n/2; i++ {
		ans[i], ans[n-1-i] = ans[n-1-i], ans[i]
	}
	return string(ans)
}

func main() {
	fmt.Println(licenseKeyFormatting("5F3Z-2e-9-w", 4), "5F3Z-2E9W")
	fmt.Println(licenseKeyFormatting("2-5g-3-J", 2), "2-5G-3J")
}
