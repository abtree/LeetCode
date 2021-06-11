package main

import (
	"bytes"
	"fmt"
	"strconv"
)

func addOperators(num string, target int) []string {
	if len(num) == 1 || num[0] != '0' {
		tar, _ := strconv.Atoi(num)
		if tar == target {
			return []string{num}
		}
		t := target
		if t < 0 {
			t = -t
		}
		if tar <= t {
			return []string{}
		}
	}
	tmp := divided([]byte(num))
	ret := []string{}
	for _, v := range tmp {
		if calculate(v) == target {
			ret = append(ret, string(v))
		}
	}
	return ret
}

func divided(byts []byte) (ret [][]byte) {
	size := len(byts)
	if size <= 1 || byts[0] != '0' {
		ret = append(ret, byts)
	}
	for i := 1; i < size; i++ {
		ret1 := byts[:i]
		if len(ret1) > 1 && ret1[0] == '0' {
			break
		}
		ret2 := divided(byts[i:])
		for _, v := range ret2 {
			ret = append(ret, bytes.Join([][]byte{ret1, v}, []byte{'+'}))
			ret = append(ret, bytes.Join([][]byte{ret1, v}, []byte{'-'}))
			ret = append(ret, bytes.Join([][]byte{ret1, v}, []byte{'*'}))
		}
	}
	return
}

func calculate(byts []byte) int {
	n := len(byts)
	sign := 1
	op := byte(' ')
	nums := []int{}
	for i := 0; i < n; i++ {
		if byts[i] == ' ' {
			continue
		}
		if byts[i] == '+' {
			continue
		}
		if byts[i] == '-' {
			sign = -sign
			continue
		}
		if byts[i] == '*' || byts[i] == '/' {
			op = byts[i]
			continue
		}
		par := 0
		for i < n && byts[i] >= '0' && byts[i] <= '9' {
			par = par*10 + int(byts[i]-'0')
			i++
		}
		par *= sign
		sign = 1
		i--
		if op != ' ' {
			if op == '*' {
				nums[len(nums)-1] *= par
			} else {
				nums[len(nums)-1] /= par
			}
			op = ' '
		} else {
			nums = append(nums, par)
		}
	}
	ret := 0
	for _, v := range nums {
		ret += v
	}
	return ret
}

func addOperators1(num string, target int) []string {
	ret := []string{}
	byts := []byte(num)
	if len(byts) <= 0 {
		return ret
	}
	after := []int{}
	for i, _ := range byts {
		if v, err := strconv.Atoi(string(byts[i:])); err == nil {
			after = append(after, v)
		}
	}
	exp := make([]byte, len(byts)*2)
	var dfs func(target, tpos, pos, now, last int)
	dfs = func(target, tpos, pos, now, last int) {
		now = now*10 + int(byts[pos]-'0')
		exp[tpos] = byts[pos]
		tpos++
		curval := now * last
		if pos == len(byts)-1 {
			if target == curval {
				ret = append(ret, string(exp[:tpos]))
			}
			return
		}
		exp[tpos] = '*'
		dfs(target, tpos+1, pos+1, 0, curval)
		if after[pos+1] >= abs(target-curval) {
			exp[tpos] = '+'
			dfs(target-curval, tpos+1, pos+1, 0, 1)
			exp[tpos] = '-'
			dfs(target-curval, tpos+1, pos+1, 0, -1)
		}
		if now != 0{
			dfs(target, tpos, pos+1, now, last)
		}
	}
	dfs(target, 0, 0, 0, 1)
	return ret
}

func abs(i int) int {
	if i < 0 {
		return -i
	}
	return i
}

func main() {
	fmt.Println(addOperators1("123", 6))
	fmt.Println(addOperators1("232", 8))
	fmt.Println(addOperators1("105", 5))
	fmt.Println(addOperators1("3456237490", 9191))
	fmt.Println(addOperators1("00", 0))
	fmt.Println(addOperators1("000", 0))
	fmt.Println(addOperators1("2147483647", 2147483647))
	fmt.Println(addOperators1("2147483648", -2147483648))
}
