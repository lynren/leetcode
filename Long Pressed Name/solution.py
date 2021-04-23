def isLongPressedName(name: str, typed: str) -> bool:
    name_idx = 0
    typed_idx = 0

    while typed_idx < len(typed) and name_idx < len(name):
        # if characters match
        if name[name_idx] == typed[typed_idx]:
            name_idx += 1
            typed_idx += 1

        # else check if next typed char is redundant
        elif typed_idx >= 1 and typed[typed_idx - 1] == typed[typed_idx]:
            typed_idx += 1
        
        # else non-redundant mismatch
        else:
            return False

    # if typed finishes before name
    if name_idx != len(name):
        return False

    # if name finishes before typed
    if typed_idx != len(typed):
        while typed_idx < len(typed):
            # check if next typed character is not redundant
            if typed[typed_idx] != typed[typed_idx - 1]:
                return False
            typed_idx += 1

    # when all tests passed, return True
    return True

def main():
    name = input("name: ")
    typed = input("typed: ")

    print(isLongPressedName(name, typed))

if __name__ == "__main__":
    main()
