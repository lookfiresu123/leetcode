package test

import (
	"fmt"
	"strings"
)

// 构建一个26位的数组，每个位置表示一个字母，数组中的值表示该字母在source中出现的次数
// 将数组中的值转换为字符串，用.连接起来，返回字符串
func buildKey(source string) string {
	bitvec := make([]int, 26)
	for index := range bitvec {
		bitvec[index] = 0
	}
	for _, v := range source {
		index := v - 'a'
		bitvec[index]++
	}
	fmt.Println(bitvec)

	bitvecrune := make([]string, 26)
	for index, v := range bitvec {
		bitvecrune[index] = fmt.Sprintf("%v", v)
	}
	return strings.Join(bitvecrune, ".")
}

// 将strs中的每个字符串转换为key，然后根据key将字符串分组
func GroupAnagrams(strs []string) [][]string {
	mymap := make(map[string][]string)
	for _, str := range strs {
		key := buildKey(str)
		mymap[key] = append(mymap[key], str)
	}

	res := make([][]string, 0)
	for _, v := range mymap {
		res = append(res, v)
	}
	return res
}

// 测试函数
func GroupAnagramsTest() {
	strs := []string{"eat", "tea", "tan", "ate", "nat", "bat"}
	res := GroupAnagrams(strs)
	for _, v := range res {
		fmt.Println(strings.Join(v, ","))
	}
}
