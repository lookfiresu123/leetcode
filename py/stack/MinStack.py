class MinStack(object):

    def __init__(self):
        self.activeBlockMin = []
        self.activeBlockOrder = []
        self.size = 0
        
    def push(self, x):
        self.activeBlockOrder.append(x)
        if self.size == 0 or self.activeBlockMin[-1] >= x:
            self.activeBlockMin.append(x)
        self.size += 1
        
    def pop(self):
        if self.size > 0:
            x = self.activeBlockOrder.pop()
            if self.activeBlockMin[-1] == x:
                self.activeBlockMin.pop()
            self.size -= 1

    def top(self):
        if self.size == 0:
            return None
        return self.activeBlockOrder[-1]
        

    def getMin(self):
        if self.size == 0:
            return None
        return self.activeBlockMin[-1]
