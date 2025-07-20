package test

import (
	"fmt"
	"sync"
)

type FooBar struct {
	n     int
	fooCh chan int
	barCh chan int
}

func NewFooBar(n int) *FooBar {
	fooBar := &FooBar{
		n:     n,
		fooCh: make(chan int, 1),
		barCh: make(chan int, 1),
	}
	fooBar.fooCh <- 0
	return fooBar
}

func (fb *FooBar) Foo(printFoo func()) {
	for i := 0; i < fb.n; i++ {
		// printFoo() outputs "foo". Do not change or remove this line.
		select {
		case <-fb.fooCh:
			printFoo()
			fb.barCh <- i
		}
	}
}

func (fb *FooBar) Bar(printBar func()) {
	for i := 0; i < fb.n; i++ {
		// printBar() outputs "bar". Do not change or remove this line.
		select {
		case <-fb.barCh:
			printBar()
			fb.fooCh <- i
		}
	}
}

func FooBarTest() {
	fooBar := NewFooBar(5)
	var wg sync.WaitGroup
	wg.Add(1)
	go func() {
		defer wg.Done()
		fooBar.Foo(func() {
			fmt.Printf("foo")
		})
	}()

	wg.Add(1)
	go func() {
		defer wg.Done()
		fooBar.Bar(func() {
			fmt.Printf("bar")
		})
	}()

	wg.Wait()
}
