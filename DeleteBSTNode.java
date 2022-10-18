/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class DeleteBSTNode {
    public void deleteNode(ListNode node) {
        ListNode prev = node;
        while(node.next != null){
            node.val = node.next.val;
            prev = node;
            node = node.next;
        }
        
        prev.next = null;
    }
}
