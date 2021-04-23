def reverse(x):
    if not x:
        return x

    negative = False
    if x < 0:
        negative = True
        x = -x

    res = 0

    while x > 0:
        # shift current res left
        res = (res * 10) + (x % 10)
        x //= 10

    
    # handle negative x
    if negative:
        res *= - 1

    # test if reversed integer over/under flows
    if not pow(-2, 31) < res < pow(2, 31) - 1:
        return 0

    return res

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
