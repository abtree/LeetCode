package main

import "fmt"

type WordDictionary struct {
	Children map[rune]*WordDictionary
	IsEnd    bool
}

/** Initialize your data structure here. */
func Constructor() WordDictionary {
	return WordDictionary{
		Children: make(map[rune]*WordDictionary),
	}
}

func (this *WordDictionary) AddWord(word string) {
	node := this
	for _, c := range word {
		n, ok := node.Children[c]
		if !ok || n == nil {
			n = &WordDictionary{
				Children: make(map[rune]*WordDictionary),
			}
			node.Children[c] = n
		}
		node = n
	}
	node.IsEnd = true
}

func (this *WordDictionary) Search(word string) bool {
	node := this
	ok := false
	src := []rune(word)
	for i, c := range src {
		if c == rune('.') {
			return node.searchDot(src, i+1)
		} else {
			node, ok = node.Children[c]
			if !ok || node == nil {
				return false
			}
		}
	}
	return node.IsEnd
}

func (this *WordDictionary) searchDot(word []rune, pos int) bool {
	ok := false
	for _, node := range this.Children {
		if node == nil {
			continue
		}
		end := true
		for i := pos; i < len(word); i++ {
			if word[i] == rune('.') {
				if node.searchDot(word, i+1) {
					return true
				}
				end = false
				break
			} else {
				node, ok = node.Children[word[i]]
				if !ok || node == nil {
					end = false
					break
				}
			}
		}
		if end && node.IsEnd {
			return true
		}
	}
	return false
}

func main() {
	wd := Constructor()
	wd.AddWord("张三")
	wd.AddWord("张大千")
	wd.AddWord("往往")
	wd.AddWord("往事")
	wd.AddWord("往事随风")
	wd.AddWord("张三丰")
	wd.AddWord("张家人")
	wd.AddWord("张abcde")
	fmt.Println(wd.Search("张.千"), " -> true")
	fmt.Println(wd.Search("往..."), " -> true")
	fmt.Println(wd.Search("张3"), " -> false")
	fmt.Println(wd.Search("往."), " -> true")
	fmt.Println(wd.Search(".事"), " -> true")
	fmt.Println(wd.Search(".abc.."), " -> true")
	fmt.Println(wd.Search("...e"), " -> false")
	fmt.Println(wd.Search("....e."), " -> false")
	fmt.Println(wd.Search("......"), " -> true")
	fmt.Println(wd.Search("张....e"), " -> true")
}
