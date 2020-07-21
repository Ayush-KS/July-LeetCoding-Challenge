# Remove Linked List Elements

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        if head == None:
            return head
        
        if head.val == val:
            return self.removeElements(head.next, val)
        
        head.next = self.removeElements(head.next, val)
        
        return head