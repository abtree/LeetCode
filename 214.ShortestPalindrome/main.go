package main

import "fmt"

func shortestPalindrome(s string) string {
	end := -1
	tt := []byte(s)
	t := []byte{'#'}
	for _, c := range tt {
		t = append(t, c)
		t = append(t, '#')
	}
	armLen := make([]int, len(t))
	j, jright := -1, -1
	for i := 0; i < len(t); i++ {
		curArmLen := 0
		if jright > i {
			iSym := j*2 - i
			minArmLen := min(armLen[iSym], jright-i)
			curArmLen = getCurArmLen(t, i-minArmLen, i+minArmLen)
		} else {
			curArmLen = getCurArmLen(t, i, i)
		}
		armLen[i] = curArmLen
		if i+curArmLen > jright {
			j = i
			jright = i + curArmLen
		}
		if i-curArmLen == 0 {
			end = i + curArmLen
		}
	}
	q := []byte{}
	for i := len(t) - 1; i > end; i-- {
		if t[i] != '#' {
			q = append(q, t[i])
		}
	}
	return string(q) + s
}

func getCurArmLen(t []byte, start, end int) int {
	for start >= 0 && end < len(t) && t[start] == t[end] {
		start--
		end++
	}
	return (end - start - 2) / 2
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Println(shortestPalindrome("aacecaaa"), " -> aaacecaaa")
	fmt.Println(shortestPalindrome("abcd"), " -> dcbabcd")
	fmt.Println(shortestPalindrome("abb"), " -> bbabb")
}
