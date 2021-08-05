package main

import (
	"fmt"
	"sort"
)

type SummaryRanges struct {
	data []int
}

/** Initialize your data structure here. */
func Constructor() SummaryRanges {
	return SummaryRanges{
		data: make([]int, 0),
	}
}

func (this *SummaryRanges) AddNum(val int) {
	this.data = append(this.data, val)
	sort.Ints(this.data)
}

func (this *SummaryRanges) GetIntervals() [][]int {
	ret := [][]int{}
	size := len(this.data)
	b := 0
	for i := 1; i < size; i++ {
		if this.data[i] == this.data[i-1] {
			continue
		}
		if this.data[i] != this.data[i-1]+1 {
			ret = append(ret, []int{this.data[b], this.data[i-1]})
			b = i
		}
	}
	ret = append(ret, []int{this.data[b], this.data[len(this.data)-1]})
	return ret
}

type SummaryRanges1 struct {
	data [][]int
}

/** Initialize your data structure here. */
func Constructor1() SummaryRanges1 {
	return SummaryRanges1{
		data: make([][]int, 0),
	}
}

func (this *SummaryRanges1) AddNum(val int) {
	for i, v := range this.data {
		if v[1] < val-1 {
			continue
		}
		if v[0] == val || v[1] == val {
			return
		}
		if v[0] > val+1 {
			tmp := this.data[i:]
			tmp1 := make([][]int, len(tmp))
			copy(tmp1, tmp)
			this.data = this.data[:i]
			this.data = append(this.data, []int{val, val})
			this.data = append(this.data, tmp1...)
			return
		}
		if v[0] == val+1 {
			this.data[i][0] = val
			return
		}
		if v[1] == val-1 {
			this.data[i][1] = val
			if i+1 == len(this.data) {
				return
			}
			if this.data[i+1][0] == val+1 {
				this.data[i][1] = this.data[i+1][1]
				tmp := this.data[i+2:]
				this.data = this.data[:i+1]
				this.data = append(this.data, tmp...)
				return
			}
		}
		return
	}
	this.data = append(this.data, []int{val, val})
}

func (this *SummaryRanges1) GetIntervals() [][]int {
	return this.data
}

func main() {
	sum := Constructor1()
	sum.AddNum(6)
	fmt.Println(sum.GetIntervals())
	sum.AddNum(6)
	fmt.Println(sum.GetIntervals())
	sum.AddNum(0)
	fmt.Println(sum.GetIntervals())
	sum.AddNum(4)
	fmt.Println(sum.GetIntervals())
	sum.AddNum(8)
	fmt.Println(sum.GetIntervals())
	sum.AddNum(7)
	fmt.Println(sum.GetIntervals())
	sum.AddNum(6)
	fmt.Println(sum.GetIntervals())
	sum.AddNum(4)
	fmt.Println(sum.GetIntervals())
	sum.AddNum(7)
	fmt.Println(sum.GetIntervals())
	sum.AddNum(5)
	fmt.Println(sum.GetIntervals())
}
