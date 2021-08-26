package main

import "fmt"

func isAdditiveNumber(num string) bool {
	dat := []byte(num)
	n := len(dat)
	if n < 3 {
		return false
	}
	for i, _ := range dat {
		dat[i] -= '0'
	}
	halfn := n/2 + 1
	tmp := make([]byte, n)
	size := 0
	for i := 0; i < halfn; i++ {
		for j := i + 1; j < n; j++ {
			if j > i+1 && dat[i+1] == 0 {
				reset(tmp, size)
				break
			}
			bytescopy(dat, tmp, i)
			size = addTwoBytes(dat, tmp, i, i, j)
			if n-j <= size {
				reset(tmp, size)
				break
			}
			k := j + 1
			suc := true
			start := i
			if k >= n {
				suc = false
			}
			for k < n {
				if compare(dat, tmp, size, k) == false {
					suc = false
					break
				}
				os := size
				size = addTwoBytes(dat, tmp, size, start, k-1)
				start = k - 1
				k += os + 1
			}
			if suc {
				return true
			}
			reset(tmp, size)
		}
	}
	return false
}

func bytescopy(dat, tmp []byte, i int) {
	k := 0
	for i >= 0 {
		tmp[k] = dat[i]
		i--
		k++
	}
}

func reset(tmp []byte, i int) {
	for i >= 0 {
		tmp[i] = 0
		i--
	}
}

func addTwoBytes(dat, tmp []byte, size, i, j int) int {
	k := 0
	for j > i {
		tmp[k] += dat[j]
		if tmp[k] > 9 {
			tmp[k] -= 10
			tmp[k+1] += 1
		}
		j--
		k++
	}
	if k <= size {
		return size
	}
	if tmp[k] > 0 {
		return k
	}
	return k - 1
}

func compare(dat, tmp []byte, size, k int) bool {
	if len(dat)-k <= size {
		return false
	}
	for size >= 0 {
		if tmp[size] != dat[k] {
			return false
		}
		k++
		size--
	}
	return true
}

func main() {
	fmt.Println(isAdditiveNumber("199001200"), false)
	fmt.Println(isAdditiveNumber("111"), false)
	fmt.Println(isAdditiveNumber("111122335588143"), true)
	fmt.Println(isAdditiveNumber("199111992"), true)
	fmt.Println(isAdditiveNumber("199100199"), true)
	fmt.Println(isAdditiveNumber("10"), false)
	fmt.Println(isAdditiveNumber("112358"), true)
	fmt.Println(isAdditiveNumber("111222333555888"), true)
}
