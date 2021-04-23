def isPalindrome(x):
    rev = 0
    exp = 0
    temp = x 
    while temp > 0:
        rev += (temp % 10) * pow(10, exp)
        temp //= 10
        exp += 1

    print("%d = %d" % (x, rev))
    # check if x == rev(x)
    if x == rev:
        return True

    return False

def main():
    x = int(input("input: "))
    print("%d %s a palindrome" % (x, "is" if isPalindrome(x) else "is not"))

if __name__ == "__main__":
    main()
