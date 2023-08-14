package main

import (
	"container/list"
	"fmt"
)

type Node struct {
	Key  int
	Val  int
	Freq int
}

type LFUCache struct {
	minFreq int
	mCap    int
	mTable  map[int]*list.Element
	mTree   map[int]*list.List
}

func Constructor(capacity int) LFUCache {
	return LFUCache{
		minFreq: 0,
		mCap:    capacity,
		mTable:  make(map[int]*list.Element),
		mTree:   make(map[int]*list.List),
	}
}

func (this *LFUCache) Get(key int) int {
	if this.mCap < 1 {
		return -1
	}
	el, ok := this.mTable[key]
	if !ok || el == nil {
		return -1
	}
	node := el.Value.(*Node)
	val, freq := node.Val, node.Freq
	l := this.mTree[freq]
	l.Remove(el)
	if l.Len() == 0 {
		delete(this.mTree, freq)
		if this.minFreq == freq {
			this.minFreq++
		}
	}
	freq++
	l = this.mTree[freq]
	if l == nil {
		l = list.New()
		this.mTree[freq] = l
	}
	el = l.PushFront(&Node{
		Key:  key,
		Val:  val,
		Freq: freq,
	})
	this.mTable[key] = el
	return val
}

func (this *LFUCache) Put(key int, value int) {
	if this.mCap < 1 {
		return
	}
	el, ok := this.mTable[key]
	if ok {
		node := el.Value.(*Node)
		freq := node.Freq
		l := this.mTree[freq]
		l.Remove(el)
		if l.Len() == 0 {
			delete(this.mTree, freq)
			if this.minFreq == freq {
				this.minFreq++
			}
		}
		freq++
		l = this.mTree[freq]
		if l == nil {
			l = list.New()
			this.mTree[freq] = l
		}
		nel := l.PushFront(&Node{
			Key:  key,
			Val:  value,
			Freq: freq,
		})
		this.mTable[key] = nel
	} else {
		if len(this.mTable) == this.mCap {
			l := this.mTree[this.minFreq]
			oel := l.Back()
			delete(this.mTable, oel.Value.(*Node).Key)
			l.Remove(oel)
			if l.Len() == 0 {
				delete(this.mTree, this.minFreq)
			}
		}
		l := this.mTree[1]
		if l == nil {
			l = list.New()
			this.mTree[1] = l
		}
		el = l.PushFront(&Node{
			Key:  key,
			Val:  value,
			Freq: 1,
		})
		this.mTable[key] = el
		this.minFreq = 1
	}
}

func main() {
	cls := Constructor(2)
	cls.Put(2, 1)
	cls.Put(2, 2)
	fmt.Println(cls.Get(2), 2)
	cls.Put(1, 1)
	cls.Put(4, 1)
	fmt.Println(cls.Get(2), 2)

	// cls := Constructor(2)
	// cls.Put(1, 1)
	// cls.Put(2, 2)
	// fmt.Println(cls.Get(1), 1)
	// cls.Put(3, 3)
	// fmt.Println(cls.Get(2), -1)
	// fmt.Println(cls.Get(3), 3)
	// cls.Put(4, 4)
	// fmt.Println(cls.Get(1), -1)
	// fmt.Println(cls.Get(3), 3)
	// fmt.Println(cls.Get(4), 4)
}
