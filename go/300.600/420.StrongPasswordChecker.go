package main

import (
	"fmt"
)

type pii struct {
	char byte
	cnt  int
}

func strongPasswordChecker(password string) int {
	byts := []byte(password)
	//检查长度
	size := len(byts)
	lack := 0
	if size < 6 {
		lack = 6 - size
	} else if size > 20 {
		lack = 20 - size
	}
	//统计连续相同字符数量和字符类型
	cnts := []pii{}
	typs := make([]int, 3)
	for i, x := range byts {
		typcr(x, typs, 1)
		if i > 0 && byts[i-1] == byts[i] {
			cnts[len(cnts)-1].cnt += 1
		} else {
			cnts = append(cnts, pii{x, 1})
		}
	}
	//删除多余字符
	add := 0
	if lack < 0 {
		add = -lack
	}
	for lack < 0 {
		biggest := 0
		for i, x := range cnts {
			if x.cnt > 0 && x.cnt%3 == 0 {
				lack += 1
				cnts[i].cnt -= 1
				typcr(x.char, typs, -1)
				if lack >= 0 {
					break
				}
			}
			biggest = max(biggest, cnts[i].cnt)
		}
		if lack < 0 {
			if biggest > 3 {
				gonext := true
				for i, x := range cnts {
					if x.cnt > 3 && x.cnt%3 == 1 {
						typcr(x.char, typs, -1)
						cnts[i].cnt -= 1
						lack += 1
						gonext = false
						break
					}
				}
				if gonext {
					for i, x := range cnts {
						if x.cnt > 3 && x.cnt%3 == 2 {
							typcr(x.char, typs, -1)
							cnts[i].cnt -= 1
							lack += 1
							break
						}
					}
				}
			} else {
				for i, x := range cnts {
					if x.cnt > 0 && typcnt(x.char, typs) > 1 {
						typcr(x.char, typs, -1)
						cnts[i].cnt -= 1
						lack += 1
						break
					}
				}
			}
		}
	}
	//统计连续超过3的
	repeat := 0
	for _, x := range cnts {
		repeat += x.cnt / 3
	}
	//统计缺失的字符类型
	typcnt := 0
	for _, x := range typs {
		if x == 0 {
			typcnt += 1
		}
	}
	return max(lack, max(typcnt, repeat)) + add
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func typcr(c byte, typs []int, val int) {
	if c >= 'a' && c <= 'z' {
		typs[0] += val
	} else if c >= 'A' && c <= 'Z' {
		typs[1] += val
	} else {
		typs[2] += val
	}
}

func typcnt(c byte, typs []int) int {
	if c >= 'a' && c <= 'z' {
		return typs[0]
	} else if c >= 'A' && c <= 'Z' {
		return typs[1]
	} else {
		return typs[2]
	}
}

func main() {
	fmt.Println(strongPasswordChecker("aaaaabbbb1234567890ABA"), 3)
	fmt.Println(strongPasswordChecker("1Abababcaaaabababababa"), 2)
	fmt.Println(strongPasswordChecker("FFFFFFFFFFFFFFF11111111111111111111AAA"), 23)
	fmt.Println(strongPasswordChecker("bbaaaaaaaaaaaaaaacccccc"), 8)
	fmt.Println(strongPasswordChecker("a"), 5)
	fmt.Println(strongPasswordChecker("aA1"), 3)
	fmt.Println(strongPasswordChecker("1337C0d3"), 0)
	fmt.Println(strongPasswordChecker("ABABABABABABABABABAB1"), 2)
}
