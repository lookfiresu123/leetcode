class HashNode(object):
    def __init__(self, key, value):
        self.key = key
        self.val = value
        self.next = None

class MyHashMap(object):
    def __init__(self):
        self.buckets = [None]
        self.maxFactor = 3
        self.size = 0
        self.bucketsNum = 1
    
    def rehash(self):
        newBucketsNum = self.bucketsNum * 2
        newBuckets = [None for x in range(0, newBucketsNum)]
        for head in self.buckets:
            cur = head
            while cur != None:
                index = cur.key % newBucketsNum
                t = HashNode(cur.key, cur.val)
                if newBuckets[index] == None:
                    newBuckets[index] = t
                else:
                    newHead = newBuckets[index]
                    while newHead.next != None:
                        newHead = newHead.next
                    newHead.next = t
                cur = cur.next
        self.buckets = []
        self.buckets = newBuckets
        self.bucketsNum = newBucketsNum
        
        
    def put(self, key, value):
        if float(self.size+1)/self.maxFactor > self.bucketsNum:
            self.rehash()
        index = key % self.bucketsNum
        if self.buckets[index] == None:
            t = HashNode(key, value)
            self.buckets[index] = t
        else:
            cur = self.buckets[index]
            prev = None
            while cur != None:
                if cur.key == key:
                    cur.val = value
                    break
                prev = cur
                cur = cur.next
            if cur == None:
                t = HashNode(key, value)
                prev.next = t
        self.size += 1      

    def get(self, key):
        index = key % self.bucketsNum
        cur = self.buckets[index]
        while cur != None and key != cur.key:
            cur = cur.next
        if cur == None:
            return -1
        return cur.val

    def remove(self, key):
        index = key % self.bucketsNum
        head = self.buckets[index]
        cur = head
        if cur != None:
            prev = None
            while cur != None and key != cur.key:
                prev = cur
                cur = cur.next
            if cur != None:
                if cur == head:
                    self.buckets[index] = cur.next
                if prev != None:
                    prev.next = cur.next
                del cur
        self.size -= 1
