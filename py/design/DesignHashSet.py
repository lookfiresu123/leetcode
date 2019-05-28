class HashNode(object):
    def __init__(self, key):
        self.key = key
        self.next = None

class MyHashSet(object):
    def __init__(self):
        self.buckets = [None]
        self.bucketsNum = 1
        self.maxFactor = 3
        self.size = 0
    
    def rehash(self):
        newBucketsNum = self.bucketsNum * 2
        newBuckets = [None for x in range(0, newBucketsNum)]
        for head in self.buckets:
            cur = head
            while cur != None:
                index = cur.key % newBucketsNum
                t = HashNode(cur.key)
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
        
    def contains(self, key):
        index = key % self.bucketsNum
        cur = self.buckets[index]
        while cur != None and cur.key != key:
            cur = cur.next
        if cur == None:
            return False
        return True

    def add(self, key):
        if float(self.size+1)/self.maxFactor > self.bucketsNum:
            self.rehash()
        if self.contains(key) == False:
            index = key % self.bucketsNum
            t = HashNode(key)
            if self.buckets[index] == None:
                self.buckets[index] = t
            else:
                cur = self.buckets[index]
                while cur.next != None:
                    cur = cur.next
                cur.next = t
        self.size += 1

    def remove(self, key):
        if self.contains(key) == True:
            index = key % self.bucketsNum
            head = self.buckets[index]
            cur = head
            prev = None
            while cur != None and cur.key != key:
                prev = cur
                cur = cur.next
            if cur == head:
                self.buckets[index] = cur.next
            else:
                prev.next = cur.next
            del cur
