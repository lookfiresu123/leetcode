package test

import (
	"fmt"
	"sync"
)

type Func func(n int)

type ZeroEvenOdd struct {
	n         int
	i         int
	zeroQueue chan bool
	evenQueue chan bool
	oddQueue  chan bool
}

func NewZeroEvenOdd(n int) *ZeroEvenOdd {
	zeroEvenOdd := &ZeroEvenOdd{
		n:         n,
		i:         1,
		zeroQueue: make(chan bool, 1),
		evenQueue: make(chan bool, 1),
		oddQueue:  make(chan bool, 1),
	}
	zeroEvenOdd.zeroQueue <- true
	return zeroEvenOdd
}

func (z *ZeroEvenOdd) zero(printNumber Func) {
	defer func() {
		fmt.Println()
		fmt.Println("close zero goroutine")
		z.close()
	}()
	for _ = range z.zeroQueue {
		if z.i > z.n {
			return
		}
		printNumber(0)
		if z.i%2 == 0 {
			z.oddQueue <- true
		} else {
			z.evenQueue <- true
		}
	}
}

func (z *ZeroEvenOdd) even(printNumber Func) {
	defer func() {
		fmt.Println("close even goroutine")
	}()
	for _ = range z.evenQueue {
		printNumber(z.i)
		z.i++
		z.zeroQueue <- true
	}
}

func (z *ZeroEvenOdd) odd(printNumber Func) {
	defer func() {
		fmt.Println("close odd goroutine")
	}()
	for _ = range z.oddQueue {
		printNumber(z.i)
		z.i++
		z.zeroQueue <- true
	}
}

func (z *ZeroEvenOdd) close() {
	close(z.zeroQueue)
	close(z.evenQueue)
	close(z.oddQueue)
}

func printNumber(n int) {
	fmt.Printf("%d", n)
}

func ZeroEvenOddTest() {
	zeroEvenOdd := NewZeroEvenOdd(5)
	var wg sync.WaitGroup
	// 为三个协程都添加等待计数
	wg.Add(3)

	go func() {
		defer wg.Done()
		zeroEvenOdd.zero(printNumber)
	}()

	go func() {
		defer wg.Done()
		zeroEvenOdd.even(printNumber)
	}()

	go func() {
		defer wg.Done()
		zeroEvenOdd.odd(printNumber)
	}()

	// 等待所有协程完成
	wg.Wait()
}
