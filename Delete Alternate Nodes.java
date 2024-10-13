class Solution {
    public void deleteAlt(Node head) {
        Node cur = head;
        while(cur!=null && cur.next!=null){
            cur.next = cur.next.next;
            cur = cur.next;
        }
    }
}
