/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode smallListHead = new ListNode(0);
        ListNode small = smallListHead;
        ListNode bigListHead = new ListNode(0);
        ListNode big = bigListHead;
        ListNode current = head;
        
        //travers the list
        while (current != null) {
            //add to the small list
            if (current.val < x) {
                small.next = current;
                small = small.next;
            } else {//add to the big list
                big.next = current;
                big = big.next;
            }
            current = current.next;
        }

        big.next = null;
        //adding the big list without the leading zero
        small.next = bigListHead.next;
        //returning the combined list without the leading zero
        return smallListHead.next;
    }
}