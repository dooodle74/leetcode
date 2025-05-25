# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reorderList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: None Do not return anything, modify head in-place instead.
        """
        node = head
        n = 0
        while node:
            n += 1
            node = node.next
        half = -(n//-2)
        stack = []

        node = head
        i = 0
        while node:
            if i >= half:
                stack.append(node)
            node = node.next
            i += 1

        node = head
        while stack:
            next_node = node.next
            node.next = stack.pop()
            if node.next != next_node:
                node.next.next = next_node
            node = next_node
        
        node.next = None
        return head