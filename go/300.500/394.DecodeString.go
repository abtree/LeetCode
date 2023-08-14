package main

import (
	"fmt"
	"strings"
)

func decodeString(s string) string {
	p := 0
	isnum := func(c byte) bool{
		return (c >= '0' && c <= '9')
	}
	var decode func()string
	decode = func() string{
		build := &strings.Builder{}
		for p < len(s) && s[p] != ']'{
			if isnum(s[p]){
				x := int(s[p] - '0')
				p++;
				for s[p] != '['{
					x = x * 10 + int(s[p] - '0')
					p++
				}
				p++
				substr := decode()
				for i := 0;i<x;i++{
					build.WriteString(substr)
				}
				p++
			}else{
				build.WriteByte(s[p])
				p++
			}
		}
		return build.String()
	}
	return decode();
}

func main() {
	fmt.Println(decodeString("3[a]2[bc]"), "aaabcbc")
	fmt.Println(decodeString("3[a2[c]]"), "accaccacc")
	fmt.Println(decodeString("2[abc]3[cd]ef"), "abcabccdcdcdef")
	fmt.Println(decodeString("abc3[cd]xyz"), "abccdcdcdxyz")
}