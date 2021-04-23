class Deque:

    def __init__(self):
        self.queue = []
        self.head = 0
        self.tail = 0

    def frontInsert(self, x):
        self.queue = [x] + self.queue

    def backInsert(self, x):
        self.queue.append(x)
        self.tail += 1

    def popFront(self):
        res = self.queue[self.head]
        self.queue = self.queue[1:]

    def popBack(self):
        res = self.queue[self.tail]
        self.queue = self.queue[:self.tail]
        self.tail -= 1

def isPalindrome(x):
    dq = Deque()

    while x > 0:
        dq.backInsert(x % 10)
        x //= 10

    print(dq.queue)

    head = dq.head
    tail = dq.tail - 1

    while head < tail:
        if dq.queue[head] != dq.queue[tail]:
            return False
        head += 1
        tail -= 1

    return True

def main():
    x = int(input("input: "))
    print("%d %s a palindrome" % (x, "is" if isPalindrome(x) else "is not"))

if __name__ == "__main__":
    main()
