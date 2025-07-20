package test

import (
	"encoding/json"
	"fmt"
	"math"
)

type LRUCache struct {
	capacity int
	clock    int
	clockMap map[int]int
	data     map[int]int
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		capacity: capacity,
		clock:    0,
		clockMap: make(map[int]int),
		data:     make(map[int]int),
	}
}

func (p *LRUCache) Get(key int) int {
	if val, ok := p.data[key]; ok {
		p.clockMap[key] = p.clock
		p.clock++
		return val
	}
	return -1
}

func (p *LRUCache) Put(key int, value int) {
	p.clockMap[key] = p.clock
	p.clock++
	_, ok := p.data[key]
	if !ok && len(p.data) >= p.capacity {
		minKey := p.findMinClock()
		// fmt.Println(fmt.Sprintf("clockMap=%v, minKey=%v", p.getJsonString(p.clockMap), minKey))
		delete(p.data, minKey)
		delete(p.clockMap, minKey)
	}
	p.data[key] = value
}

func (p *LRUCache) findMinClock() int {
	minClock := math.MaxInt
	minKey := math.MaxInt
	for key, value := range p.clockMap {
		if value < minClock {
			minKey = key
			minClock = value
		}
	}
	return minKey
}

func (p *LRUCache) getJsonString(t interface{}) string {
	a, _ := json.Marshal(t)
	return string(a)
}

func LRUCacheTest() {
	cache := Constructor(2)
	cache.Put(1, 1)
	cache.Put(2, 2)
	fmt.Println(cache.Get(1))
	cache.Put(3, 3)
	fmt.Println(cache.Get(2))
	cache.Put(4, 4)
	fmt.Println(cache.Get(1))
	fmt.Println(cache.Get(3))
	fmt.Println(cache.Get(4))
}
