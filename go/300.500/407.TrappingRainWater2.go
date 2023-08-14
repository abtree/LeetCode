package main

import (
	"container/heap"
	"fmt"
)

type Item struct{
	priority int
	x int
	y int
}
type PriorityQueue []*Item

// Len is the number of elements in the collection.
func (pq PriorityQueue) Len() int {
	return len(pq)
}

// Less reports whether the element with
// index i should sort before the element with index j.
func (pq PriorityQueue) Less(i int, j int) bool {
	return pq[i].priority < pq[j].priority
}

// Swap swaps the elements with indexes i and j.
func (pq PriorityQueue) Swap(i int, j int) {
	pq[i],pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	item := x.(*Item)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil
	*pq = old[0:n-1]
	return item
}

func trapRainWater1(heightMap [][]int) int {
	if len(heightMap) < 3 || len(heightMap[0]) < 3{
		return 0;
	}
	m := len(heightMap)
	n := len(heightMap[0])
	pq := &PriorityQueue{}
	visited := make([][]bool, m)
	for i,_ := range visited{
		visited[i] = make([]bool, n)
	}
	//加入边
	for j, x := range heightMap[0] {
		heap.Push(pq, &Item{
			priority: x,
			x:0,
			y:j,
		})
		visited[0][j] = true
	}
	for j, x := range heightMap[m-1] {
		heap.Push(pq, &Item{
			priority: x,
			x:m-1,
			y:j,
		})
		visited[m-1][j] = true
	}
	for i:=1;i<m-1;i++{
		heap.Push(pq, &Item{
			priority: heightMap[i][0],
			x:i,
			y:0,
		})
		visited[i][0] = true
		heap.Push(pq, &Item{
			priority: heightMap[i][n-1],
			x:i,
			y:n-1,
		})
		visited[i][n-1] = true
	}
	//修正值
	res := 0
	dirs := [5]int{-1, 0, 1, 0, -1}
	for pq.Len() > 0{
		item := heap.Pop(pq).(*Item)
		for i := 0;i<4;i++{
			nx := item.x + dirs[i]
			ny := item.y + dirs[i+1]
			if nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]{
				continue
			}
			if item.priority > heightMap[nx][ny]{
				res += item.priority - heightMap[nx][ny]
			}
			heap.Push(pq, &Item{
				priority: max(item.priority, heightMap[nx][ny]),
				x:nx,
				y:ny,
			})
			visited[nx][ny] = true
		}
	}

	return res
}

func max(i, j int) int{
	if i > j{
		return i
	}
	return j
}

func min(i, j int) int{
	if i < j{
		return i
	}
	return j
}

func trapRainWater2(heightMap [][]int) int {
	if len(heightMap) < 3 || len(heightMap[0]) < 3{
		return 0;
	}
	m := len(heightMap)
	n := len(heightMap[0])
	heightest := 0
	for _, row := range heightMap{
		for _, x := range row{
			heightest = max(heightest, x)
		}
	}
	water := make([][]int, m)
	for i,_ := range water{
		water[i] = make([]int, n)
		for j,_ := range water[i]{
			water[i][j] = heightest
		} 
	}
	type pair struct{x, y int}
	q := []pair{}
	for j, x := range heightMap[0] {
		if x < water[0][j]{
			water[0][j] = x
			q = append(q, pair{0, j})
		}
	}
	for j, x := range heightMap[m-1] {
		if x < water[m-1][j]{
			water[m-1][j] = x
			q = append(q, pair{m-1, j})
		}
	}
	for i:=1;i<m-1;i++{
		if heightMap[i][0] < water[i][0]{
			water[i][0] = heightMap[i][0]
			q = append(q, pair{i, 0})
		}
		if heightMap[i][n-1] < water[i][n-1]{
			water[i][n-1] = heightMap[i][n-1]
			q = append(q, pair{i, n-1})
		}
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	for len(q) > 0{
		p := q[0]
		q = q[1:]
		for i:=0;i<4;i++{
			x := p.x + dirs[i]
			y := p.y + dirs[i+1]
			if x < 0 || x >= m || y < 0 || y >= n{
				continue
			}
			if water[x][y] > water[p.x][p.y] && water[x][y] > heightMap[x][y]{
				water[x][y] = max(water[p.x][p.y], heightMap[x][y])
				q = append(q, pair{x, y})
			}
		}
	}
	ans := 0
	for i, row := range heightMap{
		for j, x := range row{
			ans += water[i][j] - x
		}
	}
	return ans
}

func trapRainWater3(heightMap [][]int) int {
	n, m := len(heightMap), len(heightMap[0])
	outBound := make([][]int, n)
	for i := 0; i < len(outBound); i++ {
		outBound[i] = make([]int, m)
	}
	sum := 0
	flag := true
	round := 1
	// 重复一次又一次的在四周取最小值
	for flag {
		flag = false
		// 计算内围的每个点最低外边：顺序初始化一遍
		for i := 1; i < n-1; i++ {
			for j := 1; j < m-1; j++ {
				// 上边和左边的最小值
				newBound := min(max(heightMap[i-1][j], outBound[i-1][j]), max(heightMap[i][j-1], outBound[i][j-1]))
				if newBound < outBound[i][j] || round == 1 {
					flag = true
					outBound[i][j] = newBound
				}
			}
		}
		//	 计算 右边和下边的最小值
		for i := n - 2; i > 0; i-- {
			for j := m - 2; j > 0; j-- {
				newBound := min(max(heightMap[i+1][j], outBound[i+1][j]), max(heightMap[i][j+1], outBound[i][j+1]))
				if newBound < outBound[i][j] || round == 1 {
					outBound[i][j] = newBound
					flag = true
				}
			}
		}
		round++
	}
	for i := 1; i < n-1; i++ {
		for j := 1; j < m-1; j++ {
			if heightMap[i][j] < outBound[i][j] {
				sum += outBound[i][j] - heightMap[i][j]
			}
		}
	}
	return sum
}

func main() {
	fmt.Println(trapRainWater1([][]int{{1, 4, 3, 1, 3, 2}, { 3,2,1,3,2,4 }, { 2,3,3,2,3,1 }}), 4)
	fmt.Println(trapRainWater1([][]int{{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}}), 10)
	fmt.Println(trapRainWater2([][]int{{1, 4, 3, 1, 3, 2}, { 3,2,1,3,2,4 }, { 2,3,3,2,3,1 }}), 4)
	fmt.Println(trapRainWater2([][]int{{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}}), 10)
	fmt.Println(trapRainWater3([][]int{{1, 4, 3, 1, 3, 2}, { 3,2,1,3,2,4 }, { 2,3,3,2,3,1 }}), 4)
	fmt.Println(trapRainWater3([][]int{{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}}), 10)
}