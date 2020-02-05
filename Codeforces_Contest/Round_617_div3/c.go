package main

// import "fmt"

// const maxn int = 2e5 + 10

// type pair struct {
// 	fir, sec int
// }

// var t int

// func main() {
// 	fmt.Scan(&t)
// 	for ; t > 0; t-- {
// 		var n int
// 		var s string
// 		fmt.Scan(&n, &s)
// 		s = " " + s
// 		var ans, l, r, x, y = n + 1, 0, 0, 0, 0
// 		m := make(map[pair]int)
// 		m[pair{0, 0}] = 1
// 		for i := 1; i < len(s); i++ {
// 			switch s[i] {
// 			case 'L':
// 				x--
// 			case 'R':
// 				x++
// 			case 'U':
// 				y++
// 			case 'D':
// 				y--
// 			}
// 			v := m[pair{x, y}]
// 			if v != 0 {
// 				if ans > (i - v + 1) {
// 					ans = i - v + 1
// 					l = v
// 					r = i
// 				}
// 			}
// 			m[pair{x, y}] = i + 1
// 		}
// 		if ans == (n + 1) {
// 			fmt.Println("-1")
// 		} else {
// 			fmt.Println(l, r)
// 		}
// 	}
// }
