def isPalindrome(x):
    dq = []

    while x > 0:
        dq.append(x % 10)
        x //= 10

    head = 0
    tail = len(dq) - 1

    while head < tail:
        if dq[head] != dq[tail]:
            return False
        head += 1
        tail -= 1

    return True

def main():
    x = int(input("input: "))
    print("%d %s a palindrome" % (x, "is" if isPalindrome(x) else "is not"))

if __name__ == "__main__":
    main()
