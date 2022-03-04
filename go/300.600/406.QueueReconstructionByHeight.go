package main

import (
	"fmt"
	"sort"
)

func reconstructQueue(people [][]int) [][]int {
	sort.Slice(people, func(i, j int)bool{
		if people[i][0] < people[j][0]{
			return false
		}
		if people[i][0] == people[j][0] && people[i][1] > people[j][1]{
			return false
		}
		return true
	})
	for i:=0; i< len(people);i++{
		if i > people[i][1]{
			ta := people[i][0]
			tb := people[i][1]
			for j:=i;j>tb;j--{
				copy(people[j], people[j-1])
			}
			people[tb][0] = ta
			people[tb][1] = tb
		}
	}
	return people
}

func main() {
	fmt.Println(reconstructQueue([][]int{ {7, 0}, { 4,4 }, { 7,1 }, { 5,0 }, { 6,1 }, { 5,2 }}));
	fmt.Println(reconstructQueue([][]int{{6, 0}, { 5,0 }, { 4,0 }, { 3,2 }, { 2,2 }, { 1,4 }}));
}