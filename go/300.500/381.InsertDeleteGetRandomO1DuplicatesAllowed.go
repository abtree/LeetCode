package main

import (
	"fmt"
	"math/rand"
	"time"
)

type RandomizedCollection struct {
	kvs  map[int]map[int]struct{}
	data []int
}

/** Initialize your data structure here. */
func Constructor() RandomizedCollection {
	rand.Seed(time.Now().UnixNano())
	return RandomizedCollection{
		kvs:  map[int]map[int]struct{}{},
		data: []int{},
	}
}

/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
func (this *RandomizedCollection) Insert(val int) bool {
	l := len(this.data)
	this.data = append(this.data, val)
	if _, ok := this.kvs[val]; ok {
		this.kvs[val][l] = struct{}{}
	} else {
		this.kvs[val] = map[int]struct{}{}
		this.kvs[val][l] = struct{}{}
	}
	return len(this.kvs[val]) == 1
}

/** Removes a value from the collection. Returns true if the collection contained the specified element. */
func (this *RandomizedCollection) Remove(val int) bool {
	end := len(this.data) - 1
	if end < 0 {
		return false
	}
	if this.data[end] == val {
		delete(this.kvs[val], end)
		if len(this.kvs[val]) == 0 {
			delete(this.kvs, val)
		}
		this.data = this.data[:end]
		return true
	}
	if kv, ok := this.kvs[val]; ok {
		for pos := range kv {
			delete(kv, pos)
			this.data[pos] = this.data[end]
			delete(this.kvs[this.data[end]], end)
			this.kvs[this.data[end]][pos] = struct{}{}
			this.data = this.data[:end]
			break
		}
		if len(this.kvs[val]) == 0 {
			delete(this.kvs, val)
		}
		return true
	}
	return false
}

/** Get a random element from the collection. */
func (this *RandomizedCollection) GetRandom() int {
	pos := rand.Intn(len(this.data))
	return this.data[pos]
}

func main() {
	cls := Constructor()
	fmt.Println(cls.Insert(10), true)
	fmt.Println(cls.Insert(10), false)
	fmt.Println(cls.Insert(20), true)
	fmt.Println(cls.Insert(20), false)
	fmt.Println(cls.Insert(30), true)
	fmt.Println(cls.Insert(30), false)
	fmt.Println(cls.Remove(10), true)
	fmt.Println(cls.Remove(20), true)
	fmt.Println(cls.Remove(20), true)
	fmt.Println(cls.Remove(10), true)
	fmt.Println(cls.Remove(30), true)
	fmt.Println(cls.Insert(40), true)
	fmt.Println(cls.Remove(30), true)
	fmt.Println(cls.Remove(30), false)
	fmt.Println(cls.GetRandom())
	fmt.Println(cls.GetRandom())
}
