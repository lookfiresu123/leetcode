class MyQueue(object):

    def __init__(self):
        self.activeBlock = []
        self.inactiveBlock = []
        self.peekVal = 0
        
    def push(self, x):
        if len(self.activeBlock) == 0:
            self.peekVal = x
        self.activeBlock.append(x)
        
    def pop(self):
        if len(self.activeBlock) > 0:
            while len(self.activeBlock) > 0:
                self.inactiveBlock.append(self.activeBlock.pop())
            x = self.inactiveBlock.pop()
            if len(self.inactiveBlock) > 0:
                self.peekVal = self.inactiveBlock.pop()
                self.activeBlock.append(self.peekVal)
            while len(self.inactiveBlock) > 0:
                self.activeBlock.append(self.inactiveBlock.pop())
            return x
        
    def peek(self):
        if len(self.activeBlock) > 0:
            return self.peekVal
        
    def empty(self):
        return len(self.activeBlock) == 0
