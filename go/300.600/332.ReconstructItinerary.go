package main

import (
	"fmt"
	"sort"
)

func findItinerary(tickets [][]string) []string {
	dp := map[string][]string{}
	for _, v := range tickets {
		dp[v[0]] = append(dp[v[0]], v[1])
	}
	for _, v := range dp {
		sort.Strings(v)
	}
	ret := []string{}
	var dfs func(cur string)
	dfs = func(cur string) {
		v, ok := dp[cur]
		for ok && len(v) > 0 {
			c := v[0]
			dp[cur] = v[1:]
			dfs(c)
			v, ok = dp[cur]
		}
		ret = append(ret, cur)
	}
	dfs("JFK")
	//reverse
	for i := 0; i < len(ret)/2; i++ {
		ret[i], ret[len(ret)-i-1] = ret[len(ret)-i-1], ret[i]
	}
	return ret
}

func main() {
	fmt.Println(findItinerary([][]string{{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}}))
	fmt.Println(findItinerary([][]string{{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}}))
}
