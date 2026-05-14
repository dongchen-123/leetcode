# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if not list1:
            if not list2:
                return None
            else:
                return list2
        elif not list2:
            return list1
        else:
            head = ListNode(min(list1.val, list2.val))
            current = head
            if list2.val <= list1.val:
                list2 = list2.next
            else:
                list1 = list1.next
            while list1 and list2:
                if list2.val <= list1.val:
                    current.next = list2
                    list2 = list2.next
                else:
                    current.next = list1
                    list1 = list1.next
                current = current.next
            if not list1:
                current.next = list2
            else:
                current.next = list1
        return head