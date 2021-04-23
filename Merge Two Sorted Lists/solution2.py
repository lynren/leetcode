class ListNode:

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def mergeTwoLists(l1, l2):
    if l1 or l2 is None:
        return l1 if l2 is None else l2

    # insert l1 into l2
    if l1.val > l2.val:
        head = l2
        insert_index = l2
        insertee = l1
    else:
        head = l1
        insert_index = l1
        insertee = l2

    while insert_index.next is not None and insertee is not None:
        if insertee.val < insert_index.val:
            temp = insertee
            insertee = insertee.next
            temp.next = insert_index.next
            insert_index.next = temp
        else:
            insert_index = insert_index.next

    if insert_index.next is None:
        insert_index.next = insertee

    return head

