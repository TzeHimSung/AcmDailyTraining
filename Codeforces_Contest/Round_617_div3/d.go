package main

import (
	"fmt"
	"sort"
)

const maxn int = 2e5 + 10

var n, a, b, k, ans, cost int
var hh [maxn]int

func main() {
	fmt.Scan(&n, &a, &b, &k)
	cost = b / a
	if b%a != 0 {
		cost++
	}
	for i := 1; i <= n; i++ {
		fmt.Scan(&hh[i])
		hh[i] = hh[i] % (a + b)
	}
	h := hh[:n+1]
	sort.Ints(h)
	for i := n; i >= 1; i-- {
		if h[i] <= a && h[i] >= 1 {
			ans++
		} else if h[i] == 0 && k-cost >= 0 {
			k -= cost
			ans++
		}
	}
	fmt.Println(ans)
}
