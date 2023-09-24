/*You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int num) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = num;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL;
    struct ListNode* current = NULL;
    int carry = 0;

    while(l1 != NULL || l2 != NULL || carry){
        int num1 = (l1 != NULL) ? l1->val : 0;
        int num2 = (l2 != NULL) ? l2->val : 0;
        int sum = num1 + num2 + carry;

        // calculate the carry for next sum
        carry = sum / 10;
        // only summing the first digit
        sum = sum % 10;

        struct ListNode* newNode = createNode(sum);

        // first node
        if(head == NULL) {
            head = newNode;
            current = head;
        }else{
            current->next = newNode;
            current = newNode;
        }

        if (l1 != NULL) {l1 = l1->next;}
        if (l2 != NULL) {l2 = l2->next;}
    }

    return head;
}
