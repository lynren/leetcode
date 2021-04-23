def isValid(s: str) -> bool:
    open_stack = list()
    matches = {
        "]" : "[",
        ")" : "(",
        "}" : "{" 
              }
    
    for c in s:
        if c in ("]", "}", ")"):
            if len(open_stack) == 0:
                return False
            if open_stack.pop() != matches[c]:
                return False
        else:
            open_stack.append(c)
            
    if len(open_stack) != 0:
        return False
    
    return True
