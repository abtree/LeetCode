package main

import (
	"fmt"
	"sort"
)

func reversePairs(nums []int) int {
	size := len(nums)
	if size < 2 {
		return 0
	}
	var reversePair func(left, right int) int
	reversePair = func(left, right int) int {
		if left >= right {
			return 0
		}
		mid := (left + right) / 2
		n1 := reversePair(left, mid)
		n2 := reversePair(mid+1, right)
		ret := n1 + n2
		// 计算区间之间
		i := left
		j := mid + 1
		for i <= mid {
			for j <= right && nums[i] > 2*nums[j] {
				j++
			}
			ret += (j - mid - 1)
			i++
		}
		// 排序并合并
		sorted := make([]int, right-left+1)
		i = left
		j = mid + 1
		p := 0
		for i <= mid || j <= right {
			if i > mid {
				sorted[p] = nums[j]
				j++
				p++
			} else if j > right {
				sorted[p] = nums[i]
				i++
				p++
			} else {
				if nums[i] > nums[j] {
					sorted[p] = nums[j]
					j++
					p++
				} else {
					sorted[p] = nums[i]
					i++
					p++
				}
			}
		}
		for p = 0; p < len(sorted); p++ {
			nums[left+p] = sorted[p]
		}
		return ret
	}
	return reversePair(0, size-1)
}

type BIT struct {
	tree []int
}

func newBit(n int) *BIT {
	return &BIT{
		tree: make([]int, n+1),
	}
}

func (bit *BIT) add(i, d int) {
	for ; i < len(bit.tree); i += (i & -i) {
		bit.tree[i] += d
	}
}
func (bit *BIT) sum(i int) int {
	res := 0
	for ; i > 0; i &= i - 1 {
		res += bit.tree[i]
	}
	return res
}

func reversePairs1(nums []int) int {
	size := len(nums)
	if size < 2 {
		return 0
	}
	allNums := make([]int, 0, 2*size)
	for _, v := range nums {
		allNums = append(allNums, v, 2*v)
	}
	sort.Ints(allNums)
	k := 1
	kth := map[int]int{allNums[0]: k}
	for i := 1; i < 2*size; i++ {
		k++
		kth[allNums[i]] = k
	}
	t := newBit(k)
	cnt := 0
	for i, v := range nums {
		cnt += i - t.sum(kth[2*v])
		t.add(kth[v], 1)
	}
	return cnt
}

func main() {
	fmt.Println(reversePairs1([]int{1, 3, 2, 3, 1}), 2)
	fmt.Println(reversePairs1([]int{2, 4, 3, 5, 1}), 3)
}
