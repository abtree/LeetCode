package main

import (
	"container/list"
	"fmt"
)

type node struct {
	keys  map[string]struct{}
	count int
}

type AllOne struct {
	lst   *list.List
	nodes map[string]*list.Element
}

func Constructor() AllOne {
	return AllOne{
		lst:   list.New(),
		nodes: map[string]*list.Element{},
	}
}

func (this *AllOne) Inc(key string) {
	if cur := this.nodes[key]; cur != nil {
		curNode := cur.Value.(node)
		if nxt := cur.Next(); nxt == nil || nxt.Value.(node).count > curNode.count+1 {
			this.nodes[key] = this.lst.InsertAfter(node{map[string]struct{}{key: {}}, curNode.count + 1}, cur)
		} else {
			nxt.Value.(node).keys[key] = struct{}{}
			this.nodes[key] = nxt
		}
		delete(curNode.keys, key)
		if len(curNode.keys) == 0 {
			this.lst.Remove(cur)
		}
	} else {
		if this.lst.Front() == nil || this.lst.Front().Value.(node).count > 1 {
			this.nodes[key] = this.lst.PushFront(node{map[string]struct{}{key: {}}, 1})
		} else {
			this.lst.Front().Value.(node).keys[key] = struct{}{}
			this.nodes[key] = this.lst.Front()
		}
	}
}

func (this *AllOne) Dec(key string) {
	cur := this.nodes[key]
	curNode := cur.Value.(node)
	if curNode.count > 1 {
		if pre := cur.Prev(); pre == nil || pre.Value.(node).count < curNode.count-1 {
			this.nodes[key] = this.lst.InsertBefore(node{map[string]struct{}{key: {}}, curNode.count - 1}, cur)
		} else {
			pre.Value.(node).keys[key] = struct{}{}
			this.nodes[key] = pre
		}
	} else {
		delete(this.nodes, key)
	}
	delete(curNode.keys, key)
	if len(curNode.keys) == 0 {
		this.lst.Remove(cur)
	}
}

func (this *AllOne) GetMaxKey() string {
	if b := this.lst.Back(); b != nil {
		for key := range b.Value.(node).keys {
			return key
		}
	}
	return ""
}

func (this *AllOne) GetMinKey() string {
	if b := this.lst.Front(); b != nil {
		for key := range b.Value.(node).keys {
			return key
		}
	}
	return ""
}

func main() {
	cls := Constructor()
	cls.Inc("a")
	cls.Inc("b")
	cls.Inc("b")
	cls.Inc("c")
	cls.Inc("c")
	cls.Inc("c")
	cls.Dec("b")
	cls.Dec("b")
	fmt.Println("Min:", cls.GetMinKey())
	cls.Dec("a")
	fmt.Println("Max:", cls.GetMaxKey())
	fmt.Println("Min:", cls.GetMinKey())
}
