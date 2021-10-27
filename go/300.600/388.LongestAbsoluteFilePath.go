package main

import (
	"bytes"
	"fmt"
)

type Data struct {
	Layer   int
	Maxsize int
	IsFile  bool
}

func lengthLongestPath(input string) int {
	byts := []byte(input)
	arrbyts := bytes.Split(byts, []byte("\n"))
	List := []*Data{}
	for i, v := range arrbyts {
		dat := &Data{}
		for _, c := range v {
			if c == '\t' {
				dat.Layer++
			} else {
				dat.Maxsize++
				if c == '.' {
					dat.IsFile = true
				}
			}
		}
		if !dat.IsFile {
			dat.Maxsize++
		}
		for i--; i >= 0; i-- {
			if List[i].Layer == dat.Layer-1 {
				dat.Maxsize += List[i].Maxsize
				break
			}
		}
		List = append(List, dat)
	}
	max := 0
	for _, x := range List {
		if x.IsFile && x.Maxsize > max {
			max = x.Maxsize
		}
	}
	return max
}

func main() {
	fmt.Println(lengthLongestPath("a\n\tb1\n\t\tf1.txt\n\taaaaa\n\t\tf2.txt"), 14)
	fmt.Println(lengthLongestPath("a"), 0)
	fmt.Println(lengthLongestPath("a\n\tsubdir1"), 0)
	fmt.Println(lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"), 32)
	fmt.Println(lengthLongestPath("file1.txt\nfile2.txt\nlongfile.txt"), 12)
}
