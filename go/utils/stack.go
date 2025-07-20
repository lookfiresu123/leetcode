package utils

import (
	"encoding/json"
	"fmt"
)

type Stack struct {
	items []interface{}
}

func NewStack() *Stack {
	return &Stack{
		items: make([]interface{}, 0),
	}
}

func (s *Stack) IsEmpty() bool {
	return len(s.items) == 0
}

func (s *Stack) Push(item interface{}) {
	s.items = append(s.items, item)
}

func (s *Stack) Pop() (interface{}, bool) {
	if s.IsEmpty() {
		return nil, false
	}
	sz := len(s.items)
	element := s.items[sz-1]
	s.items = s.items[:sz-1]
	return element, true
}

func (s *Stack) Top() (interface{}, bool) {
	if s.IsEmpty() {
		return nil, false
	}
	sz := len(s.items)
	return s.items[sz-1], true
}

func (s *Stack) Size() int {
	return len(s.items)
}

func (s *Stack) Print() {
	buf, err := json.Marshal(s.items)
	if err != nil {
		fmt.Println("error marshaling:", err)
	}
	fmt.Println("s", string(buf))
}

func StackTest() {
	stack := NewStack()
	stack.Print()
	stack.Push(1)
	stack.Print()
	stack.Push(2)
	stack.Print()
	stack.Push(3)
	stack.Print()
	stack.Pop()
	stack.Print()
	stack.Pop()
	stack.Print()
	stack.Pop()
	stack.Print()
}
