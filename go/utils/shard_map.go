package utils

import (
	"fmt"
	"sync"
	"time"
)

type ShardMap struct {
	shard []shardSegment
}

type shardSegment struct {
	mu   sync.RWMutex
	data map[interface{}]interface{}
}

func NewShardMap() *ShardMap {
	return &ShardMap{
		shard: make([]shardSegment, 16),
	}
}

func (s *ShardMap) getShard(key int) *shardSegment {
	return &s.shard[key%16]
}

func (s *ShardMap) Get(key int) interface{} {
	shard := s.getShard(key)
	shard.mu.Lock()
	defer shard.mu.Unlock()
	return shard.data[key]
}

func (s *ShardMap) Set(key int, value interface{}) {
	shard := s.getShard(key)
	shard.mu.Lock()
	defer shard.mu.Unlock()
	if shard.data == nil {
		shard.data = make(map[interface{}]interface{})
	}
	shard.data[key] = value
}

func process(s *ShardMap, start int, workerId int, wg *sync.WaitGroup) {
	defer wg.Done()
	for i := start; i < start+16; i++ {
		s.Set(1, workerId)
		t := s.Get(1)
		fmt.Printf("workerId=%d, t=%d\n", workerId, t)
		time.Sleep(100 * time.Millisecond)
	}
}

func ShardMapTest() {
	s := NewShardMap()
	var wg sync.WaitGroup
	for i := 0; i < 2; i++ {
		wg.Add(1)
		go process(s, i*16, i, &wg)
	}
	wg.Wait()
}
