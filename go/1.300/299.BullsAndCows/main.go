package main

import "fmt"

func getHint(secret string, guess string) string {
	suc := []byte(secret)
	gue := []byte(guess)
	arrsrc := [10]int{}
	arrgue := [10]int{}
	x := 0
	for i, v := range suc {
		arrsrc[int(v-'0')]++
		arrgue[int(gue[i]-'0')]++
		if v == gue[i] {
			x++
		}
	}
	y := 0
	for i, v := range arrsrc {
		y += min(v, arrgue[i])
	}
	y -= x
	return fmt.Sprintf("%dA%dB", x, y)
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func main() {
	fmt.Println(getHint("1807", "7810"), "1A3B")
	fmt.Println(getHint("1123", "0111"), "1A1B")
	fmt.Println(getHint("11", "10"), "1A0B")
}
