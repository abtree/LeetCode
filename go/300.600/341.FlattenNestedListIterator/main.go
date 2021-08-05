package main

import "fmt"

type NestedInteger struct {
	Val  int
	List []*NestedInteger
}

func (this NestedInteger) IsInteger() bool {
	return len(this.List) == 0
}

func (this NestedInteger) GetInteger() int {
	return this.Val
}

func (n *NestedInteger) SetInteger(value int) {
	n.Val = value
}

func (this *NestedInteger) Add(elem NestedInteger) {
	this.List = append(this.List, &elem)
}

func (this NestedInteger) GetList() []*NestedInteger {
	return this.List
}

type NestedIterator struct {
	Vals []int
	Pos  int
}

func Constructor(nestedList []*NestedInteger) *NestedIterator {
	ret := &NestedIterator{}
	ret.dfs(nestedList)
	return ret
}

func (this *NestedIterator) dfs(nestedList []*NestedInteger) {
	for _, v := range nestedList {
		if v.IsInteger() {
			this.Vals = append(this.Vals, v.GetInteger())
		} else {
			this.dfs(v.List)
		}
	}
}

func (this *NestedIterator) Next() int {
	ret := this.Vals[this.Pos]
	this.Pos++
	return ret
}

func (this *NestedIterator) HasNext() bool {
	return this.Pos < len(this.Vals)
}

func main() {
	vec := []*NestedInteger{}
	vec = append(vec, &NestedInteger{})
	vec = append(vec, &NestedInteger{})
	vec = append(vec, &NestedInteger{})
	vec[0].Add(NestedInteger{Val: 1})
	vec[0].Add(NestedInteger{Val: 1})
	vec[1].SetInteger(2)
	vec[2].Add(NestedInteger{Val: 1})
	vec[2].Add(NestedInteger{Val: 1})
	iter := Constructor(vec)
	fmt.Print("[")
	for iter.HasNext() {
		fmt.Printf("%v ", iter.Next())
	}
	fmt.Println("]")

	vec = make([]*NestedInteger, 0, 2)
	vec = append(vec, &NestedInteger{Val: 1})
	vec = append(vec, &NestedInteger{})
	vec[1].Add(NestedInteger{Val: 4})
	vec[1].Add(NestedInteger{})
	vec[1].List[1].Add(NestedInteger{Val: 6})
	iter = Constructor(vec)
	fmt.Print("[")
	for iter.HasNext() {
		fmt.Printf("%v ", iter.Next())
	}
	fmt.Println("]")
}
