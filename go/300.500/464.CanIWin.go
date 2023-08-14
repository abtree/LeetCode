package main

import (
	"fmt"
)

func canIWin(maxChoosableInteger int, desiredTotal int) bool {
	if maxChoosableInteger*(maxChoosableInteger+1)/2 < desiredTotal {
		return false
	}
	mem := map[int]bool{}
	var dfs func(used, cur int) bool
	dfs = func(used, cur int) bool {
		if mem[used] {
			return mem[used]
		}
		ret := false
		for i := 0; i < maxChoosableInteger; i++ {
			if ((used >> i) & 1) == 0 {
				if i+1+cur >= desiredTotal {
					ret = true
					break
				}
				if !dfs(used|(1<<i), cur+i+1) {
					ret = true
					break
				}
			}
		}
		mem[used] = ret
		return ret
	}
	return dfs(0, 0)
}

func main() {
	fmt.Println(canIWin(10, 11), false)
	fmt.Println(canIWin(10, 0), true)
	fmt.Println(canIWin(10, 1), true)
}
