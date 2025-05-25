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
        slow = head
        fast = head
        while fast and fast.next:
            fast = fast.next.next
            if fast:
                slow = slow.next
        # now slow is the last element not to be stacked
        stack = []
        slow = slow.next
        while slow:
            stack.append(slow)
            slow = slow.next

        node = head
        while stack:
            next_node = node.next
            node.next = stack.pop()
            if node.next != next_node:
                node.next.next = next_node
            node = next_node
        
        node.next = None
        return head