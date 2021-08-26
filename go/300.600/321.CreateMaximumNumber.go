package main

import "fmt"

func maxNumber(nums1 []int, nums2 []int, k int) []int {
	lsize, rsize := len(nums1), len(nums2)
	start, end := max(0, k-rsize), min(k, lsize)
	ret := make([]int, k)
	for i := start; i <= end; i++ {
		numl := subarray(nums1, i)
		numr := subarray(nums2, k-i)
		merged := merge(numl, numr)
		if compare(merged, 0, ret, 0) > 0 {
			ret = merged
		}
	}
	return ret
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func subarray(nums []int, k int) []int {
	ret := make([]int, k)
	top := -1
	remain := len(nums) - k
	for _, v := range nums {
		for top >= 0 && ret[top] < v && remain > 0 {
			top--
			remain--
		}
		if top < k-1 {
			top++
			ret[top] = v
		} else {
			remain--
		}
	}
	return ret
}

func merge(numl, numr []int) []int {
	i, j := 0, 0
	lsize, rsize := len(numl), len(numr)
	ret := make([]int, lsize+rsize)
	k := 0
	for i < lsize && j < rsize {
		if compare(numl, i, numr, j) > 0 {
			ret[k] = numl[i]
			i++
		} else {
			ret[k] = numr[j]
			j++
		}
		k++
	}
	for i < lsize {
		ret[k] = numl[i]
		i++
		k++
	}
	for j < rsize {
		ret[k] = numr[j]
		j++
		k++
	}
	return ret
}

func compare(numl []int, l int, numr []int, r int) int {
	lsize, rsize := len(numl), len(numr)
	for l < lsize && r < rsize {
		if cmp := numl[l] - numr[r]; cmp != 0 {
			return cmp
		}
		l++
		r++
	}
	return (lsize - l) - (rsize - r)
}

func main() {
	fmt.Println(maxNumber([]int{3, 4, 6, 5}, []int{9, 1, 2, 5, 8, 3}, 5))
	fmt.Println(maxNumber([]int{6, 7}, []int{6, 0, 4}, 5))
	fmt.Println(maxNumber([]int{3, 9}, []int{8, 9}, 3))
	fmt.Println(maxNumber([]int{3, 4, 1, 2, 3, 6, 5}, []int{9, 1, 2, 5, 8, 3}, 6))
	fmt.Println(maxNumber([]int{3, 4, 1, 2, 3, 6, 5, 3, 2, 1}, []int{9, 1, 2, 5, 8, 3}, 6))
}
