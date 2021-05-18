package main

import "fmt"

type Trie struct {
	Children map[rune]*Trie
	IsEnd    bool
}

/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{
		Children: make(map[rune]*Trie),
	}
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	node := this
	for _, c := range word {
		n, ok := node.Children[c]
		if !ok {
			n = &Trie{
				Children: make(map[rune]*Trie),
			}
			node.Children[c] = n
		}
		node = n
	}
	node.IsEnd = true
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	node := this.GetNode(word)
	return node != nil && node.IsEnd
}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	node := this.GetNode(prefix)
	return node != nil
}

func (this *Trie) GetNode(word string) *Trie {
	node := this
	var ok bool
	for _, c := range word {
		node, ok = node.Children[c]
		if !ok || node == nil {
			return nil
		}
	}
	return node
}

func main() {
	tree := &Trie{
		Children: make(map[rune]*Trie),
	}
	tree.Insert("apple")
	fmt.Printf("%v -> true \n", tree.Search("apple"))
	fmt.Printf("%v -> false \n", tree.Search("app"))
	fmt.Printf("%v -> true \n", tree.StartsWith("app"))
	tree.Insert("app")
	fmt.Printf("%v -> true \n", tree.Search("app"))
}
