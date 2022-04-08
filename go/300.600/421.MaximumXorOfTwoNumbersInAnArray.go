package main

import "fmt"

func findMaximumXOR(nums []int) int {
	x := 0
	for i := 30; i >= 0; i-- {
		seen := map[int]struct{}{}
		for _, x := range nums {
			seen[x>>i] = struct{}{}
		}
		xn := x*2 + 1
		found := false
		for _, x := range nums {
			if _, ok := seen[(x>>i)^xn]; ok {
				found = true
				break
			}
		}
		if found {
			x = xn
		} else {
			x = xn - 1
		}
	}
	return x
}

type Trie struct {
	left  *Trie
	right *Trie
}

var root *Trie

func add(num int) {
	cur := root
	for i := 30; i >= 0; i-- {
		bit := (num >> i) & 1
		if bit == 0 {
			if cur.left == nil {
				cur.left = &Trie{}
			}
			cur = cur.left
		} else {
			if cur.right == nil {
				cur.right = &Trie{}
			}
			cur = cur.right
		}
	}
}
func check(num int) int {
	cur := root
	x := 0
	for i := 30; i >= 0; i-- {
		bit := (num >> i) & 1
		if bit == 0 {
			if cur.right != nil {
				x = x*2 + 1
				cur = cur.right
			} else {
				x = x * 2
				cur = cur.left
			}
		} else {
			if cur.left != nil {
				x = x*2 + 1
				cur = cur.left
			} else {
				x = x * 2
				cur = cur.right
			}
		}
	}
	return x
}

func findMaximumXOR1(nums []int) int {
	root = &Trie{}
	r := 0
	for i, x := range nums {
		if i == 0 {
			continue
		}
		add(nums[i-1])
		r = max(r, check(x))
	}
	return r
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func main() {
	fmt.Println(findMaximumXOR1([]int{3, 10, 5, 25, 2, 8}), 28)
	fmt.Println(findMaximumXOR1([]int{0}), 0)
	fmt.Println(findMaximumXOR1([]int{2, 4}), 6)
	fmt.Println(findMaximumXOR1([]int{8, 10, 2}), 10)
	fmt.Println(findMaximumXOR1([]int{14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70}), 127)
}
