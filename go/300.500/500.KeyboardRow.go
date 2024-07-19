package main

import (
	"bytes"
	"fmt"
)

var (
	group = map[byte]int{
		'q': 0,
		'w': 0,
		'e': 0,
		'r': 0,
		't': 0,
		'y': 0,
		'u': 0,
		'i': 0,
		'o': 0,
		'p': 0,
		'a': 1,
		's': 1,
		'd': 1,
		'f': 1,
		'g': 1,
		'h': 1,
		'j': 1,
		'k': 1,
		'l': 1,
		'z': 2,
		'x': 2,
		'c': 2,
		'v': 2,
		'b': 2,
		'n': 2,
		'm': 2}
	rowIdx = "12210111011122000010020202"
)

func findWords(words []string) []string {
	ret := []string{}
	for _, v := range words {
		size := len(v)
		if size < 2 {
			ret = append(ret, v)
			continue
		}
		byts := bytes.ToLower([]byte(v))
		idx := 3
		for i, c := range byts {
			if i == 0 {
				idx = group[c]
			} else {
				if group[c] != idx {
					idx = 3
					break
				}
			}
		}
		if idx < 3 {
			ret = append(ret, v)
		}
	}
	return ret
}

func findWords1(words []string) []string {
	ret := []string{}
	for _, v := range words {
		size := len(v)
		if size < 2 {
			ret = append(ret, v)
			continue
		}
		byts := bytes.ToLower([]byte(v))
		idx := byte('3')
		for i, c := range byts {
			if i == 0 {
				idx = rowIdx[c-'a']
			} else {
				if rowIdx[c-'a'] != idx {
					idx = '3'
					break
				}
			}
		}
		if idx < '3' {
			ret = append(ret, v)
		}
	}
	return ret
}

func main() {
	fmt.Println(findWords1([]string{"Hello", "Alaska", "Dad", "Peace"}), `["Alaska","Dad"]`)
	fmt.Println(findWords1([]string{"omk"}), `[]`)
	fmt.Println(findWords1([]string{"adsdf", "sfd"}), `["adsdf","sfd"]`)
}
