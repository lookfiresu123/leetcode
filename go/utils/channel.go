package utils

import (
	"fmt"
	"sync"
)

func processGo(threadId int, i int, cur chan int, other chan int, wg *sync.WaitGroup) {
	for i := range cur {
		fmt.Println(fmt.Sprintf("%d,%d", threadId, i))
		i = i + 1
		other <- i
		if i > 99 {
			break
		}
	}
	wg.Done()
}

func ChannelTest() {
	i := 1
	ch1 := make(chan int, 1)
	ch2 := make(chan int, 1)
	ch1 <- i

	var wg sync.WaitGroup

	for k := 0; k < 2; k++ {
		wg.Add(1)
		if k == 0 {
			go processGo(k, i, ch1, ch2, &wg)
		} else {
			go processGo(k, i, ch2, ch1, &wg)
		}
	}
	wg.Wait()
}
