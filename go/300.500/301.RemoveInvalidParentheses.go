package main

import "fmt"

func removeInvalidParentheses(s string) []string {
	src := []byte(s)
	rml, rmr := 0, 0
	for _, v := range src {
		if v == '(' {
			rml++
		} else if v == ')' {
			if rml > 0 {
				rml--
			} else {
				rmr++
			}
		}
	}
	ret := map[string]struct{}{}
	dfs(src, 0, 0, rml, rmr, ret, nil)
	ans := make([]string, 0, len(ret))
	for k, _ := range ret {
		ans = append(ans, k)
	}
	return ans
}

func dfs(src []byte, left, right, rml, rmr int, ret map[string]struct{}, dst []byte) {
	for len(src) > 0 {
		if src[0] == '(' {
			if rml > 0 {
				dfs(src[1:], left, right, rml-1, rmr, ret, dst)
			}
			left++
		} else if src[0] == ')' {
			if rmr > 0 {
				dfs(src[1:], left, right, rml, rmr-1, ret, dst)
			}
			if left <= right {
				return
			}
			right++
		}
		dst = append(dst, src[0])
		src = src[1:]
	}
	if rmr == 0 && rml == 0 {
		if _, ok := ret[string(dst)]; !ok {
			ret[string(dst)] = struct{}{}
		}
	}
}

func main() {
	fmt.Println(removeInvalidParentheses("()())()"))
	fmt.Println(removeInvalidParentheses("(a)())()"))
	fmt.Println(removeInvalidParentheses(")("))
}
