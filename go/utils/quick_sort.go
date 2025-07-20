package utils

import "fmt"

func exch(arr []int, i int, j int) {
	arr[i], arr[j] = arr[j], arr[i]
}

func partition(arr []int, left int, right int) int {
	i := left
	j := right
	v := arr[i]
	i++
	for {
		for arr[i] < v {
			if i == right {
				break
			}
			i++
		}
		for arr[j] >= v {
			if j == left {
				break
			}
			j--
		}
		if i >= j {
			break
		}
		exch(arr, i, j)
	}
	exch(arr, left, j)
	return j
}

func sort(arr []int, left int, right int) {
	if left < right {
		fix_position := partition(arr, left, right)
		sort(arr, left, fix_position-1)
		sort(arr, fix_position+1, right)
	}
}

func quickSort(arr []int) {
	sort(arr, 0, len(arr)-1)
}

func QuickSortTest() {
	arr := []int{5, 4, 3, 2, 1}
	quickSort(arr)
	fmt.Println(arr)
}
