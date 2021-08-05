package main

import "fmt"

type Trie struct {
	Children map[byte]*Trie
	Pos      int
}

func Construct() *Trie {
	return &Trie{
		Children: make(map[byte]*Trie),
		Pos:      -1,
	}
}

func (this *Trie) Insert(word string, pos int) {
	node := this
	byts := []byte(word)
	for _, c := range byts {
		n := node.getChild(c)
		if n == nil {
			n = Construct()
			node.Children[c] = n
		}
		node = n
	}
	node.Pos = pos
}

func (this *Trie) Search(word []byte, start, end int) int {
	node := this
	for end >= start {
		node = node.getChild(word[end])
		if node == nil {
			return -1
		}
		end--
	}
	return node.Pos
}

func (this *Trie) getChild(c byte) *Trie {
	n, ok := this.Children[c]
	if !ok {
		return nil
	}
	return n
}

func isPalindrome(word []byte, start, end int) bool {
	for start < end {
		if word[start] != word[end] {
			return false
		}
		start++
		end--
	}
	return true
}

func palindromePairs(words []string) [][]int {
	trie := Construct()
	for i, v := range words {
		trie.Insert(v, i)
	}
	ret := [][]int{}
	for i, v := range words {
		byts := []byte(v)
		size := len(byts)
		for j := 0; j <= size; j++ {
			if isPalindrome(byts, j, size-1) {
				x := trie.Search(byts, 0, j-1)
				if x > -1 && x != i {
					ret = append(ret, []int{i, x})
				}
			}
			if j > 0 && isPalindrome(byts, 0, j-1) {
				x := trie.Search(byts, j, size-1)
				if x > -1 && x != i {
					ret = append(ret, []int{x, i})
				}
			}
		}
	}
	return ret
}

func reverse(str string) string {
	byts := []byte(str)
	start, end := 0, len(byts)-1
	for start < end {
		byts[start], byts[end] = byts[end], byts[start]
		start++
		end--
	}
	return string(byts)
}

func palindromePairs1(words []string) [][]int {
	wordsRev := map[string]int{}
	for i, v := range words {
		wordsRev[reverse(v)] = i
	}
	ret := [][]int{}
	for i, v := range words {
		byts := []byte(v)
		size := len(byts)
		for j := 0; j <= size; j++ {
			if isPalindrome(byts, j, size-1) {
				x, ok := wordsRev[string(byts[:j])]
				if ok && x != i {
					ret = append(ret, []int{i, x})
				}
			}
			if j > 0 && isPalindrome(byts, 0, j-1) {
				x, ok := wordsRev[string(byts[j:])]
				if ok && x != i {
					ret = append(ret, []int{x, i})
				}
			}
		}
	}
	return ret
}

func main() {
	fmt.Println(palindromePairs1([]string{"abcd", "dcba", "lls", "s", "sssll"}))
	fmt.Println(palindromePairs1([]string{"bat", "tab", "cat"}))
	fmt.Println(palindromePairs1([]string{"a", ""}))
}
