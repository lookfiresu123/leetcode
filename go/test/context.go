package test

import (
	"context"
	"fmt"
	"time"
)

func contextWithCancelWorkerProcess(workerId int, ctx context.Context) {
	for i := 0; ; i++ {
		select {
		case <-ctx.Done():
			fmt.Println(fmt.Sprintf("workerId=%v, exit", workerId))
			return
		default:
			fmt.Println(fmt.Sprintf("workerId=%v, round=%v", workerId, i))
			time.Sleep(100 * time.Microsecond)
		}
	}
}

func ContextWithCancelTest() {
	ctx, cancel := context.WithCancel(context.Background())
	for i := 0; i < 2; i++ {
		go contextWithCancelWorkerProcess(i, ctx)
	}
	time.Sleep(300 * time.Microsecond)
	cancel()
	time.Sleep(200 * time.Microsecond)
	fmt.Println("ContextWithCancelTest exit")
}

func contextWithTimeoutWorkerProcess(workerId int, ctx context.Context) {
	for i := 0; ; i++ {
		select {
		case <-ctx.Done():
			fmt.Println(fmt.Sprintf("workerId=%v, exit", workerId))
			return
		default:
			fmt.Println(fmt.Sprintf("workerId=%v, round=%v", workerId, i))
			time.Sleep(100 * time.Millisecond)
		}
	}
}

func ContextWithTimeoutTest() {
	ctx, cancel := context.WithTimeout(context.Background(), 500*time.Millisecond)
	defer func() {
		cancel()
		fmt.Println("ContextWithTimeoutTest exit")
		time.Sleep(300 * time.Millisecond)
	}()
	for i := 0; i < 2; i++ {
		go contextWithTimeoutWorkerProcess(i, ctx)
	}
	select {
	case <-ctx.Done():
		return
	}
}
