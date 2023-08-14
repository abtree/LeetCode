package main

import "fmt"

func removeKdigits(num string, k int) string {
	byts := []byte(num)
	for i:=0;i< k;i++{
		s := len(byts)-1
		j := 0
		for ;j < s;j++{
			if byts[j] > byts[j+1]{
				if j > 0{
					byts = append(byts[:j], byts[j+1:]...)
				}else{
					byts = byts[1:]
				}
				break;
			}
		}
		if j == s{
			byts = byts[:s]
		}
	}
	for len(byts) > 0 && byts[0] == '0'{
		byts = byts[1:]
	}
	if len(byts) == 0{
		return "0"
	}
	return string(byts)
}

func main() {
	fmt.Println(removeKdigits("1000", 1), "0")
	fmt.Println(removeKdigits("1432219", 3), "1219")
	fmt.Println(removeKdigits("10200", 1), "200")
	fmt.Println(removeKdigits("10", 2), "0")
}