# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):

    def mergeKLists(self, lists):
        """
        :type lists: List[Optional[ListNode]]
        :rtype: Optional[ListNode]
        """
        def merge2Lists(head1, head2):
            node = head1
            if (head1.val > head2.val):
                node = head2
                head2 = head2.next
            else:
                head1 = head1.next
            
            ret_head = node
            
            while head1 and head2:
                if head1.val <= head2.val:
                    node.next = head1
                    head1 = head1.next
                else:
                    node.next = head2
                    head2 = head2.next
                node = node.next
            
            while head1:
                node.next = head1
                node = node.next
                head1 = head1.next
            
            while head2:
                node.next = head2
                node = node.next
                head2 = head2.next
            
            return ret_head

        # start
        k = len(lists)
        if k < 1:
            return None
        if k <= 1:
            return lists[0]
        
        currList_idx = 0

        # search for the first valid list
        while currList_idx < k and not lists[currList_idx]:
            currList_idx += 1

        if currList_idx == k:
            return None # No valid lists
        
        currList_head = lists[currList_idx]
        
        # merge all valid lists starting from next one
        for nextList_idx in range(currList_idx + 1, k):
            if not lists[nextList_idx]:
                continue
            nextList_head = lists[nextList_idx]
            currList_head = merge2Lists(currList_head, nextList_head)
        
        return currList_head
