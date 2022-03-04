package main

import (
	"fmt"
	"strconv"
	"strings"
)

func readBinaryWatch(turnedOn int) []string {
	if turnedOn > 8{
		return []string{};
	}
	ret := []string{}
	h,j := 0, 0
	dp := []int{1,2,4,8,16,32}
	var fn func(b, e, v, n int)
	fn = func(b, e, v, n int){
		if n == 0{
			if e==4{
				if v < 12{
					h = v
					fn(0, 6, 0, j)
				}
			}else{
				if v < 60{
					bud := strings.Builder{}
					bud.WriteString(strconv.Itoa(h))
					bud.WriteByte(':')
					if v < 10{
						bud.WriteByte('0');
					}
					bud.WriteString(strconv.Itoa(v))
					ret = append(ret, bud.String())
				}
			}
			return
		}
		for i := b; i< e;i++{
			fn(i+1, e, v+dp[i], n-1)
		}
	}
	for i :=0; i< 4;i++{
		j = turnedOn - i;
		if j < 0{
			return ret
		}
		if j > 5{
			continue
		}
		fn(0, 4, 0, i);
	}
	return ret
}

func main() {
	fmt.Println(readBinaryWatch(0))
	fmt.Println(readBinaryWatch(4))
	fmt.Println(readBinaryWatch(5))
}