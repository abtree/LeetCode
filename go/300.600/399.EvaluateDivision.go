package main

import (
	"fmt"
	"math"
)

type SData struct {
	Groud int
	Value float64
}

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
	gid := 1
	datas := map[int]*SData{}
	//初始化
	for i, x := range equations{
		k1, k2 := stringtokey(&x[0]), stringtokey(&x[1])
		d1,ok := datas[k1]
		if !ok{
			d1 = &SData{}
			datas[k1] = d1
		}
		d2,ok := datas[k2]
		if !ok{
			d2 = &SData{}
			datas[k2] = d2
		}
		if d1.Groud == 0 && d2.Groud == 0 {
			d1.Groud = gid;
			d2.Groud = gid;
			gid++
			d2.Value = 1
			d1.Value = values[i]
		}else if d1.Groud > 0 && d2.Groud == 0 {
			d2.Groud = d1.Groud
			d2.Value = d1.Value / values[i]	
		}else if d1.Groud == 0 && d2.Groud > 0{
			d1.Groud = d2.Groud
			d1.Value = d2.Value * values[i]	
		}else if d1.Groud > 0 && d2.Groud > 0 && d1.Groud != d2.Groud{
			og := d1.Groud
			t := d2.Value*values[i]/d1.Value
			d1.Groud = d2.Groud
			d1.Value = d2.Value*values[i]
			for _, v := range datas{
				if v.Groud == og{
					v.Value *= t
					v.Groud = d2.Groud
				}
			}
		}
	}
	//求解
	ret := make([]float64, len(queries))
	for i, x := range queries{
		k1, k2 := stringtokey(&x[0]), stringtokey(&x[1])
		if d1, ok := datas[k1];!ok{
			ret[i] = -1
		}else{
			if d2, ok := datas[k2];!ok{
				ret[i] = -1
			}else{
				if d1.Groud != d2.Groud{
					ret[i] = -1
				}else{
					ret[i] = d1.Value/d2.Value
				}
			}
		}
	}
	return ret
}

func stringtokey(s *string) int {
	key := 0
	for i, c := range *s {
		if c >= 'a' && c <= 'z'{
			key += int(math.Pow(37, float64(i))) + int(c - 'a') + 1
		}else{
			key += int(math.Pow(37, float64(i))) + int(c - '0') + 27
		}
	}
	return key;
}

func main(){
	fmt.Println(calcEquation([][]string{ {"a", "b"}, { "b","c" }}, []float64{2,3}, [][]string{ {"a", "c"}, { "b","a" }, { "a","e" }, { "a","a" }, { "x","x" }}))
	fmt.Println(calcEquation([][]string{ {"a", "b"}, { "b","c" }, { "bc","cd" }}, []float64{1.5, 2.5, 5},[][]string{ {"a", "c"}, { "c","b" }, { "bc","cd" }, { "cd","bc" }}))
	fmt.Println(calcEquation([][]string{ {"a", "b"}}, []float64{0.5},[][]string{ {"a", "b"}, { "b","a" }, { "a","c" }, { "x","y" }}))
}