package test

import (
	"bufio"
	"fmt"
	"os"
)

func ScanfTest() {
	f, err := os.Open("/Users/lookfiresu/go/src/leetcode/data/scan_data.txt")
	if err != nil {
		fmt.Println(err)
		return
	}
	scanner := bufio.NewScanner(f)
	for scanner.Scan() {
		line := scanner.Text()
		fmt.Println(line)
	}
}
