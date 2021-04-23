def longestCommonPrefix(strs):
    if len(strs) < 1:
        return ""
    window = strs[0]
    window_end = len(strs[0])

    for s in strs:
        for i in range(window_end):
            if i < len(s):
                if s[i] != window[i]:
                    window_end = i
                    break
            else:
                window_end = len(s)

    return window[:window_end]

def main():
    strs = ["flower", "flow", "flight"]

    print("longest common prefix: %s" % longestCommonPrefix(strs))

    strs = ["dog", "cat", "rat"]
    print("longest common prefix: %s" % longestCommonPrefix(strs))

    strs = ["aa", "a"]
    print("longest common prefix: %s" % longestCommonPrefix(strs))

    strs = ["abab", "ab", ""]
    print("longest common prefix: %s" % longestCommonPrefix(strs))
    

if __name__ == "__main__":
    main()
