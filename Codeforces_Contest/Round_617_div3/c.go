package main

import "fmt"

const(
	maxn =2000010
)
var t int

func main() {
	fmt.Scan(&t)
	for ; t >= 0; t-- {
		var n, x, y int
		var xx[]
		var s string
		fmt.Scan(&n, &s)
		for _, i := range s {
			switch i {
			case 'L':
				x--
			case 'R':
				x++
			case 'U':
				y++
			case 'D':
				y--
			}
		}

	}
}
