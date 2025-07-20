package utils

import (
	"errors"
	"fmt"
	"sync"
	"time"
)

// Task 任务类型，无返回值
type Task func()

// SimpleThreadPool 极简线程池
type SimpleThreadPool struct {
	workers   int            // 工作协程数量
	taskQueue chan Task      // 任务队列
	wg        sync.WaitGroup // 等待组，用于等待所有任务完成
	closed    bool           // 关闭标志
	mu        sync.Mutex     // 互斥锁
}

// NewSimpleThreadPool 创建新的极简线程池
func NewSimpleThreadPool(workers int, queueSize int) *SimpleThreadPool {
	p := &SimpleThreadPool{
		workers:   workers,
		taskQueue: make(chan Task, queueSize),
		closed:    false,
	}
	p.startWorkers()
	return p
}

// workerProcess
func (p *SimpleThreadPool) workerProcess() {
	for task := range p.taskQueue {
		task()
		p.wg.Done()
	}
}

// startWorkers 启动工作协程
func (p *SimpleThreadPool) startWorkers() {
	for i := 0; i < p.workers; i++ {
		go p.workerProcess()
	}
}

// Submit 提交任务
func (p *SimpleThreadPool) Submit(task Task) error {
	p.mu.Lock()
	defer p.mu.Unlock()

	if p.closed {
		return errors.New("thread pool is closed")
	}

	p.wg.Add(1)
	select {
	case p.taskQueue <- task:
		return nil
	default:
		p.wg.Done()
		return errors.New("task queue is full")
	}
}

// Close 关闭线程池
func (p *SimpleThreadPool) Close() {
	p.mu.Lock()
	defer p.mu.Unlock()

	if !p.closed {
		p.closed = true
		close(p.taskQueue)
	}
}

// Wait 等待所有任务完成
func (p *SimpleThreadPool) Wait() {
	p.wg.Wait()
}

func Test() {
	pool := NewSimpleThreadPool(3, 5)
	defer pool.Close()

	for i := 0; i < 10; i++ {
		pool.Submit(func() {
			fmt.Println("hello world")
		})
		time.Sleep(500 * time.Millisecond)
	}
	pool.Wait()
}
