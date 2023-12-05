package main

import (
	"fmt"
	"sort"
)

type Trie struct {
	IsEnd    bool
	Children []*Trie
}

func NewTrie() *Trie {
	return &Trie{
		IsEnd:    false,
		Children: make([]*Trie, 26),
	}
}

func findAllConcatenatedWordsInADict(words []string) []string {
	sort.Slice(words, func(i, j int) bool {
		return len(words[i]) < len(words[j])
	})
	head := NewTrie()
	ans := []string{}
	for _, word := range words {
		visited := make([]bool, len(word))
		if dfs(head, word, 0, visited) {
			ans = append(ans, word)
		} else {
			insert(head, word)
		}
	}
	return ans
}

func dfs(head *Trie, word string, start int, visited []bool) bool {
	size := len(word)
	if size == start {
		return true
	}
	if visited[start] {
		return false
	}
	visited[start] = true
	node := head
	for i := start; i < size; i++ {
		index := int(word[i] - 'a')
		node = node.Children[index]
		if node == nil {
			return false
		}
		if node.IsEnd {
			if dfs(head, word, i+1, visited) {
				return true
			}
		}
	}
	return false
}

func insert(node *Trie, word string) {
	for _, c := range word {
		index := int(c - 'a')
		child := node.Children[index]
		if child == nil {
			child = NewTrie()
			node.Children[index] = child
		}
		node = child
	}
	node.IsEnd = true
}

func findAllConcatenatedWordsInADict1(words []string) []string {
	dic := map[string]struct{}{}
	for i := range words {
		dic[words[i]] = struct{}{}
	}
	ret := []string{}
	check := func(x int) {
		size := len(words[x])
		dp := make([]int, size+1)
		for i := 1; i <= size; i++ {
			dp[i] = -1
		}
		for i := 0; i <= size; i++ {
			if dp[i] < 0 {
				continue //表示 word[0..i]不再dic里面,没必要进行后续判断
			}
			for j := i + 1; j <= size; j++ {
				if _, ok := dic[words[x][i:j]]; ok {
					//word[i..j]也在dic里面，可以从j开始继续判断
					dp[j] = max(dp[j], dp[i]+1)
				}
			}
			if dp[size] > 1 { //表示中间至少有一个分段
				ret = append(ret, words[x])
				return
			}
		}
	}
	for x := range words {
		check(x)
	}
	return ret
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func main() {
	fmt.Println(findAllConcatenatedWordsInADict1([]string{"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"}), `["catsdogcats","dogcatsdog","ratcatdogcat"]`)
	fmt.Println(findAllConcatenatedWordsInADict1([]string{"cat", "dog", "catdog"}), `["catdog"]`)
}
