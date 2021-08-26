package main

import "fmt"

type MyStack struct {
	Queue []int
}

/** Initialize your data structure here. */
func Constructor() MyStack {
	return MyStack{Queue: []int{}}
}

/** Push element x onto stack. */
func (this *MyStack) Push(x int) {
	this.Queue = append(this.Queue, x)
}

/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
	ret := this.Top()
	this.Queue = this.Queue[:len(this.Queue)-1]
	return ret
}

/** Get the top element. */
func (this *MyStack) Top() int {
	if this.Empty() {
		return 0
	}
	return this.Queue[len(this.Queue)-1]
}

/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
	return len(this.Queue) == 0
}

func main() {
	cls := Constructor()
	cls.Push(1)
	cls.Push(2)
	fmt.Println(cls.Top(), "->2")
	fmt.Println(cls.Pop(), " -> 2")
	fmt.Println(cls.Empty(), " -> false")
	fmt.Println(cls.Top(), "->1")
}
