class ListNode:

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def mergeTwoLists(l1: ListNode, l2: ListNode) -> ListNode:
    """ Merges l1 into l2
    """
    if l2 is None and l1 is None:
        return l1

    if l2 is None:
        return l1

    if l1 is None:
        return l2

    p2 = l2

    while p2.next is not None and l1 is not None:
        # insertion point found for l1 node
        if l1.val < p2.next.val:
            temp = l1
            l1 = l1.next
            temp.next = p2.next
            p2.next = temp

        # increment l2 counter
        p2 = p2.next

    # l2 exhausted but l1 elements remain, insert rest of l1 into l2
    if l1 is not None:
        p2.next = l1

    return l2


def main():
    res = mergeTwoLists
