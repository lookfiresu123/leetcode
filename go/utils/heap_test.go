package utils

import (
	"container/heap"
	"fmt"
	"testing"
)

func TestMaxHeap(t *testing.T) {
	maxHeap := NewMaxHeap(6)
	maxHeap.items = []int{1, 2, 3, 4, 5}
	heap.Init(maxHeap)

	heap.Push(maxHeap, 8)
	fmt.Println(maxHeap.items)
	heap.Push(maxHeap, 7)
	fmt.Println(maxHeap.items)

	heap.Pop(maxHeap)
	fmt.Println(maxHeap.items)
	heap.Pop(maxHeap)
}
