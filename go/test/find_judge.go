package test

import (
	"fmt"
)

func findJudge(n int, trust [][]int) int {
	inDegrees := make([]int, n+1)
	outDegrees := make([]int, n+1)
	for _, t := range trust {
		inDegrees[t[1]]++
		outDegrees[t[0]]++
	}
	for i := 1; i <= n; i++ {
		if inDegrees[i] == n-1 && outDegrees[i] == 0 {
			return i
		}
	}
	return -1
}

func FindJudgeTest() {
	n := 3
	trust := [][]int{{1, 3}, {2, 3}}
	res := findJudge(n, trust)
	fmt.Println(res)
}
