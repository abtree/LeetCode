package main

import (
	"fmt"
	"math"
	"sort"
)

///////////////////////////////////////////////////////////////
//归并排序
func countRangeSum(nums []int, lower int, upper int) int {
	sum := make([]int, len(nums)+1)
	for i, v := range nums {
		sum[i+1] = sum[i] + v
	}

	var countRangeSumRecursive func(left int, right int) int
	countRangeSumRecursive = func(left int, right int) int {
		if left == right {
			return 0
		}
		mid := (left + right) / 2
		ret := countRangeSumRecursive(left, mid)
		ret += countRangeSumRecursive(mid+1, right)
		//统计i..l, i..l+1, ..., i..r的数量
		i, l, r := left, mid+1, mid+1
		for i <= mid {
			for l <= right && sum[l]-sum[i] < lower {
				l++
			}
			for r <= right && sum[r]-sum[i] <= upper {
				r++
			}
			ret += (r - l)
			i++
		}
		//对left..right排序
		sorted := make([]int, right-left+1)
		p, p1, p2 := 0, left, mid+1
		for p1 <= mid || p2 <= right {
			if p1 > mid {
				sorted[p] = sum[p2]
				p2++
			} else if p2 > right {
				sorted[p] = sum[p1]
				p1++
			} else {
				if sum[p1] < sum[p2] {
					sorted[p] = sum[p1]
					p1++
				} else {
					sorted[p] = sum[p2]
					p2++
				}
			}
			p++
		}
		for i, v := range sorted {
			sum[left+i] = v
		}
		return ret
	}

	return countRangeSumRecursive(0, len(nums))
}

///////////////////////////////////////////////////////////////
//线段树
type segNode []struct { //这里是用数组代替二叉树
	lo, hi, cnt int
}

func (t segNode) build(pos, left, right int) {
	t[pos].lo, t[pos].hi = left, right
	if left == right {
		return
	}
	mid := (left + right) >> 1
	t.build(pos<<1, left, mid)
	t.build(pos<<1|1, mid+1, right)
}
func (t segNode) inc(pos, val int) {
	if t[pos].lo == t[pos].hi {
		t[pos].cnt++
		return
	}
	if val <= (t[pos].lo+t[pos].hi)>>1 {
		t.inc(pos<<1, val)
	} else {
		t.inc(pos<<1|1, val)
	}
	t[pos].cnt = t[pos<<1].cnt + t[pos<<1|1].cnt
}
func (t segNode) query(pos, left, right int) (res int) {
	if left <= t[pos].lo && t[pos].hi <= right {
		return t[pos].cnt
	}
	mid := (t[pos].lo + t[pos].hi) >> 1
	if right <= mid {
		return t.query(pos<<1, left, right)
	}
	if left > mid {
		return t.query(pos<<1|1, left, right)
	}
	return t.query(pos<<1, left, right) + t.query(pos<<1|1, left, right)
}
func countRangeSum1(nums []int, lower int, upper int) (cnt int) {
	n := len(nums)

	tmp := map[int]struct{}{
		0:      struct{}{},
		-upper: struct{}{},
		-lower: struct{}{},
	}
	sum := make([]int, n+1)
	for i, v := range nums {
		sum[i+1] = sum[i] + v
		tmp[sum[i+1]] = struct{}{}
		tmp[sum[i+1]-upper] = struct{}{}
		tmp[sum[i+1]-lower] = struct{}{}
	}
	arr := []int{}
	for k, _ := range tmp {
		arr = append(arr, k)
	}
	sort.Ints(arr)
	kth := map[int]int{}
	for i, v := range arr {
		kth[v] = i + 1
	}

	t := make(segNode, 4*len(arr))
	t.build(1, 1, len(arr))
	t.inc(1, kth[0])
	for _, x := range sum[1:] {
		left, right := kth[x-upper], kth[x-lower]
		cnt += t.query(1, left, right)
		t.inc(1, kth[x])
	}
	return
}

///////////////////////////////////////////////////////////////
type node struct {
	left, right, cnt int //这里 left，right 都是存的 preSum[i]的值
	lo, hi           *node
}

func (this *node) insert(val int) {
	this.cnt++
	if this.left == this.right {
		return
	}
	mid := (this.left + this.right) >> 1
	if val <= mid {
		if this.lo == nil {
			this.lo = &node{left: this.left, right: mid}
		}
		this.lo.insert(val)
	} else {
		if this.hi == nil {
			this.hi = &node{left: mid + 1, right: this.right}
		}
		this.hi.insert(val)
	}
}

func (this *node) query(l, r int) (res int) {
	if this == nil || l > this.right || r < this.left {
		return
	}
	if l <= this.left && this.right <= r {
		return this.cnt
	}
	return this.lo.query(l, r) + this.hi.query(l, r)
}

func countRangeSum2(nums []int, lower int, upper int) (cnt int) {
	sum := make([]int, len(nums)+1)
	for i, v := range nums {
		sum[i+1] = sum[i] + v
	}

	lbound, rbound := math.MaxInt32, math.MinInt32
	for _, x := range sum {
		lbound = min(lbound, x, x-lower, x-upper)
		rbound = max(rbound, x, x-lower, x-upper)
	}
	root := &node{left: lbound, right: rbound}
	for _, x := range sum {
		l, r := x-upper, x-lower
		cnt += root.query(l, r)
		root.insert(x)
	}
	return
}

func min(a ...int) int {
	res := a[0]
	for _, v := range a[1:] {
		if v < res {
			res = v
		}
	}
	return res
}

func max(a ...int) int {
	res := a[0]
	for _, v := range a[1:] {
		if v > res {
			res = v
		}
	}
	return res
}

///////////////////////////////////////////////////////////////
//树化数组
type BIT struct {
	tree []int
}

func (this *BIT) inc(i int) {
	for ; i < len(this.tree); i += i & -i {
		this.tree[i]++
	}
}

func (this *BIT) sum(i int) (res int) {
	for ; i > 0; i &= i - 1 {
		res += this.tree[i]
	}
	return
}
func (this *BIT) query(l, r int) (res int) {
	return this.sum(r) - this.sum(l-1)
}

func countRangeSum3(nums []int, lower int, upper int) (cnt int) {
	n := len(nums)

	allNums := make([]int, 1, 3*n+1)
	sum := make([]int, n+1)
	for i, v := range nums {
		sum[i+1] = sum[i] + v
		allNums = append(allNums, sum[i+1], sum[i+1]-lower, sum[i+1]-upper)
	}
	sort.Ints(allNums)
	k := 1
	kth := map[int]int{allNums[0]: k}
	for i := 1; i <= 3*n; i++ {
		if allNums[i] != allNums[i-1] {
			k++
			kth[allNums[i]] = k
		}
	}
	t := BIT{make([]int, k+1)}
	t.inc(kth[0])
	for _, x := range sum[1:] {
		l, r := kth[x-upper], kth[x-lower]
		cnt += t.query(l, r)
		t.inc(kth[x])
	}
	return
}

///////////////////////////////////////////////////////////////

func main() {
	fmt.Println(countRangeSum3([]int{math.MinInt32, 0, math.MinInt32, math.MaxInt32}, -564, 3864), 3)
	fmt.Println(countRangeSum3([]int{math.MaxInt32, math.MinInt32, -1, 0}, -1, 0), 4)
	fmt.Println(countRangeSum3([]int{-2, 5, -1}, -2, 2), 3)
	fmt.Println(countRangeSum3([]int{0}, 0, 0), 1)
	fmt.Println(countRangeSum3([]int{-2, 5, 6, -1}, -2, 2), 2)
}
