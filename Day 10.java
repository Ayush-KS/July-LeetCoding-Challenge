// Flatten a Multilevel Doubly Linked List

class Solution {
    
    public Node helper(Node head) {
        if(head == null)
            return null;
        Node ret = head;
        while(head != null) {
            Node nextHead = head.next;
            if(head.child != null) {
                Node tail = helper(head.child);
                head.next = head.child;
                head.child.prev = head;
                head.child = null;
                tail.next = nextHead;
                if(nextHead != null)
                    nextHead.prev = tail;
            }
            head = nextHead;
        }
        
        while(ret.next != null)
            ret = ret.next;
         
        return ret;
    }
    
    public Node flatten(Node head) {
        Node tail = helper(head);
        return head;
    }
}