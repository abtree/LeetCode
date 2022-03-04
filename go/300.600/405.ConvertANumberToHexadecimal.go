package main

import (
	"fmt"
	"strings"
)

func toHex(num int) string {
	if num == 0{
		return "0"
	}
	sb := strings.Builder{}
	for i:= 7;i>=0;i--{
		val := (num >> (4*i))&0xf
		if sb.Len() >0 || val > 0{
			if val < 10{
				sb.WriteByte('0'+ byte(val));
			}else{
				sb.WriteByte('a'+ byte(val-10));
			}
		}
	}
	return sb.String()
}

func main() {
	fmt.Println(toHex(26), "1a")
	fmt.Println(toHex(-1), "ffffffff")
}