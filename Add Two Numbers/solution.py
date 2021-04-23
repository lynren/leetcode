class ListNode:
    def __init__(self, val=0, next_=None):
        self.val = val
        self.next = next_

def addTwoNumbers(l1: ListNode, l2: ListNode) -> ListNode:
    l1_idx = l1
    l2_idx = l2
    count = 0

    l2_num = l1_num = 0
    print("processing list 1")
    while l1_idx is not None:
        num_to_add = l1_idx.val * pow(10, count)
        print("adding number: %d" % num_to_add)
        l1_num += num_to_add
        l1_idx = l1_idx.next
        count += 1
        print("count: %d" % count)

    print("processing list 2")
    count = 0
    while l2_idx is not None:
        num_to_add = l2_idx.val * pow(10, count)
        print("adding number: %d" % num_to_add)
        l2_num += num_to_add
        l2_idx = l2_idx.next
        count += 1

    return l1_num + l2_num

def adder(l1, l2) -> ListNode:
    l1_idx = l1
    l2_idx = l2

    # init output list
    summation = l1_idx.val + l2_idx.val
    if summation > 9:
        carry = 1
        summation -= 10
    else:
        carry = 0

    output_list = ListNode(summation)
    output_idx = output_list
    l1_idx = l1_idx.next
    l2_idx = l2_idx.next

    while l1_idx is not None and l2_idx is not None:
        summation = l1_idx.val + l2_idx.val + carry
        # set carry if sum exceeds 9
        if summation > 9:
            carry = 1
            summation -= 10
        else:
            carry = 0
        l1_idx = l1_idx.next
        l2_idx = l2_idx.next
        new_node = ListNode(summation)
        output_idx.next = new_node
        output_idx = output_idx.next

    # if l2 finishes before l1
    while l1_idx is not None:
        summation = l1_idx.val + carry
        if summation > 9:
            carry = 1
            summation -= 10
        else:
            carry = 0
        l1_idx = l1_idx.next
        new_node = ListNode(summation)
        output_idx.next = new_node
        output_idx = output_idx.next
        
    # if l1 finishes before l2
    while l2_idx is not None:
        summation = l2_idx.val + carry
        if summation > 9:
            carry = 1
            summation -= 10
        else:
            carry = 0
        l2_idx = l2_idx.next
        new_node = ListNode(summation)
        output_idx.next = new_node
        output_idx = output_idx.next

    # if both lists exhausted but a carry remains
    if carry == 1:
        new_node = ListNode(1)
        output_idx.next = new_node

    return output_list

def printList(head):
    idx = head
    while idx is not None:
        print(idx.val, end=" -> ")
        idx = idx.next
    print("None")

def main():
    l1 = ListNode(2)
    l1_2 = ListNode(4)
    l1_3 = ListNode(3)
    l1.next = l1_2
    l1_2.next = l1_3

    l2 = ListNode(5)
    l2_1 = ListNode(6)
    l2_2 = ListNode(4)
    l2.next = l2_1
    l2_1.next = l2_2

    res = adder(l1, l2)
    printList(res)


if __name__ == "__main__":
    main()
