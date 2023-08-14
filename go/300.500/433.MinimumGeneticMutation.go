package main

import "fmt"

var (
	layer    int
	minlayer int
	mend     *string
	used     []bool
	mbank    []string
)

func minMutation(start string, end string, bank []string) int {
	layer = 0
	minlayer = len(bank) + 1
	mend = &end
	used = make([]bool, len(bank))
	mbank = bank
	mutation(&start)
	if minlayer > len(bank) {
		return -1
	}
	return minlayer
}

func mutation(start *string) {
	if layer >= minlayer {
		return
	}
	layer++
	for i, x := range mbank {
		if used[i] {
			continue
		}
		if different(start, &x) {
			if *mend == x {
				minlayer = layer
				layer--
				return
			}
			used[i] = true
			mutation(&x)
			used[i] = false
		}
	}
	layer--
}

func different(left, right *string) bool {
	cnt := 0
	for i := 0; i < 8; i++ {
		if (*left)[i] != (*right)[i] {
			cnt++
		}
	}
	return cnt == 1
}

func main() {
	fmt.Println(minMutation("AACCGGTT", "AACCGGTA", []string{"AACCGGTA"}), 1)
	fmt.Println(minMutation("AAAACCCC", "CCCCCCCC", []string{"AAAACCCA", "AAACCCCA", "AACCCCCA", "AACCCCCC", "ACCCCCCC", "CCCCCCCC", "AAACCCCC", "AACCCCCC"}), 4)
	fmt.Println(minMutation("AACCGGTT", "AAACGGTA", []string{"AACCGGTA", "AACCGCTA", "AAACGGTA"}), 2)
	fmt.Println(minMutation("AACCGGTT", "AAACGGTA", []string{"AACCGATT", "AACCGATA", "AAACGATA", "AAACGGTA"}), 4)
	fmt.Println(minMutation("AACCTTGG", "AATTCCGG", []string{"AATTCCGG", "AACCTGGG", "AACCCCGG", "AACCTACC"}), -1)
	fmt.Println(minMutation("AAAAACCC", "AACCCCCC", []string{"AAAACCCC", "AAACCCCC", "AACCCCCC"}), 3)
}
