def writeZigZag(s, num_rows):
    col = 0
    # first row placement of a zag character
    zag_index = num_rows - 2
    # first column is a zig
    zig = True

    num_cols = len(s)
    output = [[" "] * len(s) for _ in range(num_rows)]

    c = 0
    while c < len(s):
        if zig:
            for moves in range(num_rows):
                output[moves][col] = s[c]
                c += 1
            col += 1
            zig = False
        else:
            output[zag_index][col] = s[c]
            c += 1
            col += 1
            zag_index -= 1
            # if last zag character
            if zag_index == 0:
                zig = True
                # reset zag index
                zag_index = num_rows-2
        print2DArray(output)
    # print final zigzag
    print2DArray(output)

def testArray(s):
    num_rows = 4
    num_cols = len(s)

    output = [[" "] * num_cols for _ in range(num_rows)]

    print2DArray(output)

def print2DArray(arr):
    num_rows = len(arr)
    num_cols = len(arr[0])

    for x in range(num_rows):
        for y in range(num_cols):
            print(arr[x][y], end="")
        print()

def main():
    s = "PAYPALISHIRING"
    writeZigZag(s, 3)
    #testArray(s)

if __name__ == "__main__":
    main()
