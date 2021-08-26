package main

import "fmt"

type MyQueue struct {
	Stack []int
}

/** Initialize your data structure here. */
func Constructor() MyQueue {
	return MyQueue{Stack: []int{}}
}

/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int) {
	this.Stack = append(this.Stack, x)
}

/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
	i := this.Stack[0]
	this.Stack = this.Stack[1:]
	return i
}

/** Get the front element. */
func (this *MyQueue) Peek() int {
	if this.Empty() {
		return 0
	}
	return this.Stack[0]
}

/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
	return len(this.Stack) == 0
}

func main() {
	queue := Constructor()
	queue.Push(1)
	queue.Push(2)
	queue.Push(3)
	queue.Push(4)
	fmt.Println(queue.Pop(), 1)
	queue.Push(5)
	fmt.Println(queue.Pop(), 2)
	fmt.Println(queue.Pop(), 3)
	fmt.Println(queue.Pop(), 4)
	fmt.Println(queue.Pop(), 5)
}
