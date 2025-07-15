Given the head of a linked list, remove the nth node from the end of the list and return its head.

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 1;
        ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
            size++;
        }
        // If the head node is to be deleted
        if (n == size) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        int pos = size - n;
        int i = 0;
        ListNode* temp2 = head;
        while (i < pos - 1) { 
            temp2 = temp2->next; 
            i++;
        }
        ListNode* next = temp2->next;
        temp2->next = temp2->next->next;
        delete next;
        return head;
    }
};
