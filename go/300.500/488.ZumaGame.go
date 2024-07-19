package main

import (
	"bytes"
	"fmt"
	"sort"
)

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

type State struct {
	board []byte
	hand  []byte
	step  int
}

func NewState(b, h []byte, s int) *State {
	return &State{
		board: b,
		hand:  h,
		step:  s,
	}
}

func findMinStep(bs string, hs string) int {
	visited := map[string]struct{}{}
	board := []byte(bs)
	hand := []byte(hs)
	sort.Slice(hand, func(i, j int) bool {
		return hand[i] <= hand[j]
	})

	visited[bs+" "+hs] = struct{}{}
	queue := []*State{}
	queue = append(queue, NewState(board, hand, 0))
	for len(queue) > 0 {
		curr := queue[0]
		// fmt.Println("curr", string(curr.board), string(curr.hand), curr.step)
		queue = queue[1:]
		for j := 0; j < len(curr.hand); j++ {
			if j > 0 && curr.hand[j-1] == curr.hand[j] {
				continue
			}
			for i := 0; i <= len(curr.board); i++ {
				if i > 0 && curr.hand[j] == curr.board[i-1] {
					continue
				}
				choose := false
				if i < len(curr.board) && curr.board[i] == curr.hand[j] {
					choose = true
				}
				if i > 0 && i < len(curr.board) && curr.board[i-1] == curr.board[i] && curr.board[i] != curr.hand[j] {
					choose = true
				}
				if choose {
					newSource := bytes.Join([][]byte{curr.board[:i], []byte{curr.hand[j]}, curr.board[i:]}, []byte{})
					newBoard := clean(newSource)
					if len(newBoard) == 0 {
						return curr.step + 1
					}
					newHand := bytes.Join([][]byte{curr.hand[:j], curr.hand[j+1:]}, []byte{})
					key := string(newBoard) + " " + string(newHand)
					// fmt.Println("check", key)
					_, ok := visited[key]
					if !ok {
						queue = append(queue, NewState(newBoard, newHand, curr.step+1))
						visited[key] = struct{}{}
					}
				}
			}
		}
	}
	return -1
}

type pair struct {
	char  byte
	count int
}

func clean(s []byte) []byte {
	//fmt.Println("in", string(s))
	st := []*pair{}
	for _, c := range s {
		for {
			size := len(st)
			if size == 0 {
				break
			}
			pa := st[size-1]
			if c == pa.char {
				break
			}
			if pa.count < 3 {
				break
			}
			st = st[:size-1]
		}
		if len(st) == 0 || c != st[len(st)-1].char {
			st = append(st, &pair{
				char:  c,
				count: 1,
			})
		} else {
			st[len(st)-1].count += 1
		}
	}
	if len(st) > 0 && st[len(st)-1].count >= 3 {
		st = st[:len(st)-1]
	}
	res := []byte{}
	for _, v := range st {
		for j := 0; j < v.count; j++ {
			res = append(res, v.char)
		}
	}
	//fmt.Println("out", string(res))
	return res
}

var dp map[string]int

func findMinStep1(bs string, hs string) int {
	dp = map[string]int{}
	board := []byte(bs)
	hand := []byte(hs)
	sort.Slice(hand, func(i, j int) bool {
		return hand[i] <= hand[j]
	})
	ans := dfs(board, hand)
	if ans <= 5 {
		return ans
	}
	return -1
}

func dfs(board, hand []byte) int {
	if len(board) == 0 {
		return 0
	}
	key := fmt.Sprintf("%s %s", board, hand)
	if v, ok := dp[key]; ok {
		return v
	}
	res := 6
	for j := 0; j < len(hand); j++ {
		if j > 0 && hand[j] == hand[j-1] {
			continue
		}
		for i := 0; i < len(board); i++ {
			if i > 0 && board[i-1] == hand[j] {
				continue
			}
			choose := false
			if i < len(board) && board[i] == hand[j] {
				choose = true
			} else if i > 0 && i < len(board) && board[i-1] == board[i] && board[i] != hand[j] {
				choose = true
			}
			if choose {
				newSource := bytes.Join([][]byte{board[:i], []byte{hand[j]}, board[i:]}, []byte{})
				newBoard := clean(newSource)
				newHand := bytes.Join([][]byte{hand[:j], hand[j+1:]}, []byte{})
				res = min(res, dfs(newBoard, newHand)+1)
			}
		}
	}
	dp[key] = res
	return res
}

func main() {
	fmt.Println(findMinStep1("RRWWRRBBRR", "WB"), 2)
	fmt.Println(findMinStep1("RRGGBBYYWWRRGGBB", "RGBYW"), -1)
	fmt.Println(findMinStep1("BGGRRYY", "BBYRG"), 5)
	fmt.Println(findMinStep1("RBYYBBRRB", "YRBGB"), 3)
	fmt.Println(findMinStep1("WRRBBW", "RB"), -1)
	fmt.Println(findMinStep1("WWRRBBWW", "WRBRW"), 2)
	fmt.Println(findMinStep1("G", "GGGGG"), 2)
}
