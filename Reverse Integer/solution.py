def reverse(x):
    if not x:
        return x

    negative = False if x > 0 else True

    if negative:
        x *= -1

    stack = []

    while x > 0:
        stack.append(x % 10)
        x //= 10

    while stack[len(stack) - 1] == 0:
        stack.pop()

    exp = sum_ = 0
    while len(stack) > 0:
        sum_ += stack.pop() * pow(10, exp)
        exp += 1

    # handle negative x
    if negative:
        sum_ *= - 1

    # test if reversed integer over/under flows
    if not pow(-2, 31) < sum_ < pow(2, 31) - 1:
        return 0

    return sum_

def main():
    x = 321
    print(reverse(x))
    x = 1200
    print(reverse(x))
    x = -321
    print(reverse(x))
    x = -3000
    print(reverse(x))
    x = 0
    print(reverse(x))


if __name__ == "__main__":
    main()
