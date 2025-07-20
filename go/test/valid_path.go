package test

import (
	"encoding/json"
	"fmt"
)

func validPath(n int, edges [][]int, source int, destination int) bool {
	if source == destination {
		return true
	}
	tmp := make(map[int][]int)
	for _, edge := range edges {
		tmp[edge[0]] = append(tmp[edge[0]], edge[1])
		tmp[edge[1]] = append(tmp[edge[1]], edge[0])
	}

	fmt.Println(fmt.Sprintf("tmp=%v", getJsonString(tmp)))

	sz := len(tmp[source])
	duplicateMap := make(map[int]int)
	sourceVec := tmp[source]
	var i int
	start := 0
	for i < len(sourceVec) {
		for i = start; i < sz; i++ {
			fmt.Println(fmt.Sprintf("duplicateMap=%v, sourceVec=%v", getJsonString(duplicateMap), getJsonString(sourceVec)))
			if sourceVec[i] == destination {
				return true
			}
			if _, ok := duplicateMap[sourceVec[i]]; ok {
				continue
			}
			duplicateMap[sourceVec[i]] = 1
			sourceVec = append(sourceVec, tmp[sourceVec[i]]...)
		}
		start = sz
		sz = len(sourceVec)
	}

	return false
}

func getJsonString(t interface{}) string {
	a, _ := json.Marshal(t)
	return string(a)
}

func ValidPathTest() {
	n := 1
	edges := [][]int{}
	res := validPath(n, edges, 0, 0)
	fmt.Println(res)
}
