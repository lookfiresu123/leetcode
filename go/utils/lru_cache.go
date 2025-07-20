package utils

import (
	"sync"
)

/*
	LRUCache 是一个LRU缓存，它是一个线程安全的缓存，它使用一个map和一个双向链表来实现。
	map用于存储键值对，双向链表用于存储LRU缓存中的键值对，双向链表的头部是最近使用的键值对，尾部是最近最少使用的键值对。
	当缓存满时，LRUCache会删除最近最少使用的键值对。
	当缓存中不存在键值对时，LRUCache会返回-1。
	当缓存中存在键值对时，LRUCache会返回键值对。
	当缓存中存在键值对时，LRUCache会更新键值对。
*/

type node struct {
	key   string
	value interface{}
	prev  *node
	next  *node
}

type LRUCache struct {
	cache    map[string]*node
	capacity int
	mutex    sync.RWMutex
	head     *node
	tail     *node
}

func NewLRUCache(capacity int) *LRUCache {
	return &LRUCache{
		cache:    make(map[string]*node),
		capacity: capacity,
		head:     nil,
		tail:     nil,
	}
}

// Get 获取节点
func (c *LRUCache) Get(key string) interface{} {
	c.mutex.Lock()
	defer c.mutex.Unlock()

	if n, ok := c.cache[key]; ok {
		c.moveToHead(n)
		return n.value
	}

	return nil
}

// Put 添加新节点
func (c *LRUCache) Put(key string, value interface{}) {
	c.mutex.Lock()
	defer c.mutex.Unlock()

	if _, ok := c.cache[key]; ok {
		c.cache[key] = &node{
			key:   key,
			value: value,
		}
		c.moveToHead(c.cache[key])
		return
	}

	// 如果缓存满了，删除最近最少使用的节点
	if len(c.cache) >= c.capacity {
		tailNode := c.getTailNode()
		if tailNode != nil {
			delete(c.cache, tailNode.key)
		}
		c.removeTail()
	}

	// 如果缓存未满，添加新节点
	c.cache[key] = &node{
		key:   key,
		value: value,
	}

	if c.head == nil {
		c.head = c.cache[key]
	}

	if c.tail == nil {
		c.tail = c.cache[key]
	}

	c.moveToHead(c.cache[key])
}

// getTailNode 获取尾部节点
func (c *LRUCache) getTailNode() *node {
	if c.tail == nil {
		return nil
	}
	return c.tail
}

// removeTail 删除尾部节点
func (c *LRUCache) removeTail() {
	if c.tail == nil {
		return
	}

	c.tail.prev.next = nil
	c.tail = c.tail.prev
}

// moveToHead 将节点移动到头部
func (c *LRUCache) moveToHead(n *node) {
	if c.head == n {
		return
	}

	if c.tail == n {
		c.tail = n.prev
	}

	n.prev = nil
	n.next = c.head
	c.head.prev = n
	c.head = n

	if c.tail == nil {
		c.tail = n
	}
}
