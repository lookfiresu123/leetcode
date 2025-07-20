/*
在数组中，如果前面的数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
示例：​​
输入: [7,5,6,4]   [5,6,7,4] [4,5,6,7] nlogn
输出: 5
解释: 逆序对包括 (7,5)、(7,6)、(7,4)、(5,4)、(6,4)，共 5 个。

[7,6,5,4]
*/

package utils

import "fmt"

var count = 0

func swapWithCnt(arr []int, left int, right int) {
	tmp := arr[left]
	arr[left] = arr[right]
	arr[right] = tmp
	count = count + 1
}

func mergeSort(arr []int, left int, right int) {
	if left >= right {
		return
	}
	if left+1 == right && arr[left] > arr[right] {
		swapWithCnt(arr, left, right)
		return
	}
	mid := (left + right) / 2
	mergeSort(arr, left, mid)
	mergeSort(arr, mid+1, right)

	tmpLeft := append([]int{}, arr[left:mid+1]...)
	tmpRight := append([]int{}, arr[mid+1:right+1]...)
	fmt.Println(fmt.Sprintf("tmpLeft=%v, tmpRight=%v", tmpLeft, tmpRight))
	startLeft := 0
	startRight := 0
	startIndex := left
	for startLeft < len(tmpLeft) && startRight < len(tmpRight) {
		fmt.Println(fmt.Sprintf("tmpLeft[startLeft]=%v, tmpRight[startRight]=%v", tmpLeft[startLeft], tmpRight[startRight]))
		if tmpLeft[startLeft] > tmpRight[startRight] {
			arr[startIndex] = tmpRight[startRight]
			fmt.Println(fmt.Sprintf("arr[startIndex]=%v", arr[startIndex]))
			count = count + len(tmpLeft) - startLeft
			// fmt.Println(fmt.Sprintf("count=%v", count))
			startRight = startRight + 1
		} else {
			arr[startIndex] = tmpLeft[startLeft]
			fmt.Println(fmt.Sprintf("arr[startIndex]=%v", arr[startIndex]))
			startLeft = startLeft + 1
		}
		startIndex = startIndex + 1
	}

	for i := startLeft; i < len(tmpLeft); i++ {
		arr[startIndex] = tmpLeft[i]
		startIndex++
	}
	for i := startRight; i < len(tmpRight); i++ {
		arr[startIndex] = tmpLeft[i]
		startIndex++
	}
}

func MergeSortTest() {
	arr := []int{7, 6, 5, 4, 3}
	mergeSort(arr, 0, len(arr)-1)
	fmt.Println(arr)
	fmt.Println(count)
}
