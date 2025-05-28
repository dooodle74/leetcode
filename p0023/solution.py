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
            node = ListNode()            
            dummyHead = node
            
            while head1 and head2:
                if head1.val <= head2.val:
                    node.next = head1
                    head1 = head1.next
                else:
                    node.next = head2
                    head2 = head2.next
                node = node.next
            
            if head1:
                node.next = head1
            
            if head2:
                node.next = head2
            
            return dummyHead.next

        # get rid of check if valid - newer merge2 checks for it
        k = len(lists)
        if k < 1:
            return None
        if k <= 1:
            return lists[0]
        
        # divide and conq (merge sort type shi)
        # modify in place list of linkedlists
        while len(lists) > 1:
            new_lists = [] # temp array to avoid popping in place for each pair
            for i in range(0, len(lists), 2):
                list1_head = lists[i]
                list2_head = None
                if i + 1 < len(lists):
                    list2_head = lists[i+1]
                new_lists.append(merge2Lists(list1_head, list2_head))
            lists = new_lists
        
        # lists now has one big list
        return lists[0]
