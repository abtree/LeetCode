package main

import (
	"fmt"
	"strconv"
)

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
type NestedInteger struct {
	Val  int
	List []*NestedInteger
}

// Return true if this NestedInteger holds a single integer, rather than a nested list.
func (n NestedInteger) IsInteger() bool {
	return n.Val > 0
}

// Return the single integer that this NestedInteger holds, if it holds a single integer
// The result is undefined if this NestedInteger holds a nested list
// So before calling this method, you should have a check
func (n NestedInteger) GetInteger() int {
	return n.Val
}

// Set this NestedInteger to hold a single integer.
func (n *NestedInteger) SetInteger(value int) {
	n.Val = value
}

// Set this NestedInteger to hold a nested list and adds a nested integer to it.
func (n *NestedInteger) Add(elem NestedInteger) {
	n.List = append(n.List, &elem)
}

// Return the nested list that this NestedInteger holds, if it holds a nested list
// The list length is zero if this NestedInteger holds a single integer
// You can access NestedInteger's List element directly if you want to modify it
func (n NestedInteger) GetList() []*NestedInteger {
	return n.List
}

func deserialize(s string) *NestedInteger {
	byts := []byte(s)
	if byts[0] == '[' {
		ret := &NestedInteger{}
		decode(byts[1:], ret)
		return ret
	}
	ret := &NestedInteger{}
	val, _ := strconv.Atoi(s)
	ret.SetInteger(val)
	return ret
}

func decode(byts []byte, ret *NestedInteger) []byte {
	for len(byts) > 0 {
		if byts[0] == '[' {
			ret1 := &NestedInteger{}
			byts = decode(byts[1:], ret1)
			ret.Add(*ret1)
			continue
		}
		if byts[0] == ']' {
			return byts[1:]
		}
		if byts[0] == ',' {
			byts = byts[1:]
			continue
		}
		x := 0
		flag := 1
		if byts[0] == '-' {
			flag = -1
			byts = byts[1:]
		}
		for byts[0] >= '0' && byts[0] <= '9' {
			x = x*10 + (int(byts[0] - '0'))
			byts = byts[1:]
		}
		add := NestedInteger{}
		add.SetInteger(flag * x)
		ret.Add(add)
	}
	return byts
}

func main() {
	fmt.Println(deserialize("[123,456,[788,799,833],[[]],10,[]]"))
	fmt.Println(deserialize("123"))
	fmt.Println(deserialize("[123,[456,[789]]]"))
	fmt.Println(deserialize("[123,[456,789]]"))
	fmt.Println(deserialize("[123,[456,789],789]"))
}
