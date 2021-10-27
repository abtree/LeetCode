package main

import "fmt"

func lexicalOrder(n int) []int {
	ret := make([]int, 0, n)
	var dfs func(b int)
	dfs = func(b int) {
		b *= 10
		for i := 0; i < 10; i++ {
			if b+i > n {
				break
			}
			ret = append(ret, b+i)
			dfs(b + i)
		}
	}
	for i := 1; i < 10; i++ {
		if i > n {
			break
		}
		ret = append(ret, i)
		dfs(i)
	}
	return ret
}

func main() {
	fmt.Println(lexicalOrder(13))
	fmt.Println(lexicalOrder(2))
	fmt.Println(lexicalOrder(200))
}
