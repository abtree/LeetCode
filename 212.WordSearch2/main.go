package main

import (
	"fmt"
	"sync"
)

func findWords(board [][]byte, words []string) []string {
	wg := sync.WaitGroup{}
	wg.Add(len(words))
	ret := make([]string, 0, len(words))
	for _, str := range words {
		go func(str string) {
			defer wg.Done()
			src := []byte(str)
			used := make([][]bool, len(board))
			for i, _ := range used {
				used[i] = make([]bool, len(board[0]))
			}
			for i, col := range board {
				for j, row := range col {
					if row != src[0] {
						continue
					}
					if find(board, used, src, i, j, 1) {
						ret = append(ret, str)
						return
					}
				}
			}
		}(str)
	}
	wg.Wait()
	return ret
}

func find(board [][]byte, used [][]bool, src []byte, i, j int, p int) bool {
	if p >= len(src) {
		return true
	}
	used[i][j] = true
	if i > 0 && !used[i-1][j] && board[i-1][j] == src[p] {
		if find(board, used, src, i-1, j, p+1) {
			return true
		}
	}
	if i+1 < len(board) && !used[i+1][j] && board[i+1][j] == src[p] {
		if find(board, used, src, i+1, j, p+1) {
			return true
		}
	}
	if j > 0 && !used[i][j-1] && board[i][j-1] == src[p] {
		if find(board, used, src, i, j-1, p+1) {
			return true
		}
	}
	if j+1 < len(board[0]) && !used[i][j+1] && board[i][j+1] == src[p] {
		if find(board, used, src, i, j+1, p+1) {
			return true
		}
	}
	used[i][j] = false
	return false
}

type Trie struct {
	Children map[byte]*Trie
	IsEnd    bool
}

func (this *Trie) Insert(word string) {
	byts := []byte(word)
	node := this
	for _, c := range byts {
		n, ok := node.Children[c]
		if !ok || n == nil {
			n = &Trie{
				Children: make(map[byte]*Trie),
			}
			node.Children[c] = n
		}
		node = n
	}
	node.IsEnd = true
}

func (this *Trie) Delete(word string) {
	byts := []byte(word)
	this.del(byts, 0)
}

func (this *Trie) del(byts []byte, i int) {
	if i >= len(byts) {
		return
	}
	node, ok := this.Children[byts[i]]
	if !ok || node == nil {
		return
	}
	node.del(byts, i+1)
	if len(node.Children) <= 0 {
		delete(this.Children, byts[i])
	}
}

func findWords2(board [][]byte, words []string) []string {
	dic := &Trie{
		Children: make(map[byte]*Trie),
	}
	for _, str := range words {
		dic.Insert(str)
	}
	ret := []string{}
	used := make([][]bool, len(board))
	for i := range used {
		used[i] = make([]bool, len(board[0]))
	}
	size := 0
	var search func(node *Trie, i, j int, dp []byte)
	search = func(node *Trie, i, j int, dp []byte) {
		dp = append(dp, board[i][j])
		used[i][j] = true
		if node.IsEnd {
			ret = append(ret, string(dp))
			node.IsEnd = false
		}
		if i > 0 && !used[i-1][j] {
			if n, ok := node.Children[board[i-1][j]]; ok && n != nil {
				search(n, i-1, j, dp)
			}
		}
		if i+1 < len(board) && !used[i+1][j] {
			if n, ok := node.Children[board[i+1][j]]; ok && n != nil {
				search(n, i+1, j, dp)
			}
		}
		if j > 0 && !used[i][j-1] {
			if n, ok := node.Children[board[i][j-1]]; ok && n != nil {
				search(n, i, j-1, dp)
			}
		}
		if j+1 < len(board[0]) && !used[i][j+1] {
			if n, ok := node.Children[board[i][j+1]]; ok && n != nil {
				search(n, i, j+1, dp)
			}
		}
		used[i][j] = false
	}
	for i, col := range board {
		for j, row := range col {
			node, ok := dic.Children[row]
			if !ok || node == nil {
				continue
			}
			search(node, i, j, []byte{})
			for size < len(ret) {
				dic.Delete(ret[size])
				size++
			}
			if len(dic.Children) == 0 {
				return ret
			}
		}
	}
	return ret
}

func main() {
	fmt.Println(findWords2([][]byte{
		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
	}, []string{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"}))

	fmt.Println(findWords2([][]byte{
		{'o', 'a', 'a', 'n'},
		{'e', 't', 'a', 'e'},
		{'i', 'h', 'k', 'r'},
		{'i', 'f', 'l', 'v'},
	}, []string{"oath", "pea", "eat", "rain"}))

	fmt.Println(findWords2([][]byte{
		{'a', 'b'},
		{'c', 'd'},
	}, []string{"abcd"}))
}
