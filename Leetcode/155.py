class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.element, self.minVal = [], []


    def push(self, x: int) -> None:
        self.element.append(x)
        if not self.minVal or x <= self.minVal[-1]:
            self.minVal.append(x)

    def pop(self) -> None:
        if self.element is None:
            return
        if self.element[-1] == self.minVal[-1]:
            self.minVal.pop()
        self.element.pop()

    def top(self) -> int:
        return self.element[-1]

    def getMin(self) -> int:
        return self.minVal[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
