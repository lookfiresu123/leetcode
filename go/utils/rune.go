package utils

import (
	"fmt"
)

func RuneTest() {
	runeList := make([]rune, 0)
	s := string("hello world")
	for _, v := range s {
		runeList = append(runeList, v)
	}
	runeList = append(runeList, '!')
	fmt.Println(string(runeList))
}
