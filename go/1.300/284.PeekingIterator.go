package main

type Iterator struct {
}

func (this *Iterator) hasNext() bool {
	// Returns true if the iteration has more element
	return true
}
func (this *Iterator) next() int {
	// Returns the next element in the iteration.
	return 0
}

type PeekingIterator struct {
	*Iterator
	hasStore bool
	store    int
}

func Constructor(iter *Iterator) *PeekingIterator {
	return &PeekingIterator{
		Iterator: iter,
	}
}

func (this *PeekingIterator) hasNext() bool {
	if this.hasStore {
		return true
	}
	return this.Iterator.hasNext()
}

func (this *PeekingIterator) next() int {
	if this.hasStore {
		this.hasStore = false
		return this.store
	}
	return this.Iterator.next()
}

func (this *PeekingIterator) peek() int {
	if this.hasStore {
		return this.store
	}
	this.store = this.Iterator.next()
	this.hasStore = true
	return this.store
}
