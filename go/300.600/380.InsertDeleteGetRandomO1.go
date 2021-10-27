package main

import (
	"fmt"
	"math/rand"
	"time"
)

type RandomizedSet struct {
	kv   map[int]int
	data []int
}

/** Initialize your data structure here. */
func Constructor() RandomizedSet {
	rand.Seed(time.Now().UnixNano())
	return RandomizedSet{
		kv:   map[int]int{},
		data: []int{},
	}
}

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
func (this *RandomizedSet) Insert(val int) bool {
	if _, ok := this.kv[val]; ok {
		return false
	}
	this.kv[val] = len(this.data)
	this.data = append(this.data, val)
	return true
}

/** Removes a value from the set. Returns true if the set contained the specified element. */
func (this *RandomizedSet) Remove(val int) bool {
	if pos, ok := this.kv[val]; ok {
		//将要删除的元素移动到末尾
		end := len(this.data) - 1
		if end != pos {
			this.data[pos] = this.data[end]
			this.kv[this.data[end]] = pos
		}
		this.data = this.data[:end]
		delete(this.kv, val)
		return true
	}
	return false
}

/** Get a random element from the set. */
func (this *RandomizedSet) GetRandom() int {
	pos := rand.Intn(len(this.data))
	return this.data[pos]
}

func main() {
	cls := Constructor()
	fmt.Println(cls.Insert(1), true)
	fmt.Println(cls.Remove(2), false)
	fmt.Println(cls.Insert(2), true)
	fmt.Println(cls.GetRandom())
	fmt.Println(cls.Remove(1), true)
	fmt.Println(cls.Insert(2), false)
	fmt.Println(cls.GetRandom())
}
