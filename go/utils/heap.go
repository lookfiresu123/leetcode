package utils

import (
	"container/heap"
)

type MaxHeap struct {
	items    []int
	capacity int
}

func NewMaxHeap(capacity int) *MaxHeap {
	return &MaxHeap{
		items:    make([]int, 0),
		capacity: capacity,
	}
}

// 实现Len
func (h *MaxHeap) Len() int {
	return len(h.items)
}

// 实现Less
func (h *MaxHeap) Less(i, j int) bool {
	return h.items[i] > h.items[j]
}

// 实现Swap
func (h *MaxHeap) Swap(i, j int) {
	h.items[i], h.items[j] = h.items[j], h.items[i]
}

// 实现Push
func (h *MaxHeap) Push(x interface{}) {
	h.items = append(h.items, x.(int))
}

func (h *MaxHeap) PushWithCapacity(x interface{}) {
	heap.Push(h, x)
	if h.Len() > h.capacity {
		heap.Pop(h)
	}
}

// 实现Pop
func (h *MaxHeap) Pop() interface{} {
	n := len(h.items)
	x := h.items[n-1]
	h.items = h.items[0 : n-1]
	return x
}
