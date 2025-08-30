You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.






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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* left = list1;
        ListNode* right = list2;
        ListNode* nh = NULL;
        ListNode* temp = NULL;
        ListNode* prev = NULL;
        while (left != NULL && right != NULL) {
            ListNode* nn;
            if (left->val <= right->val) {
                nn = new ListNode(left->val);
                prev = left;
                left = left->next;
            } else {
                nn = new ListNode(right->val);
                prev = right;
                right = right->next;
            }
            if (nh == NULL) {
                nh = nn;
                temp = nn;
            } else {
                temp->next = nn;
                temp = temp->next;
            }
            delete prev;
        }
        while (left != NULL) {
            ListNode* nn = new ListNode(left->val);
            prev = left;
            left = left->next;
            if (nh == NULL) {
                nh = nn;
                temp = nn;
            } else {
                temp->next = nn;
                temp = temp->next;
            }
            delete prev;
        }
        while (right != NULL) {
            ListNode* nn = new ListNode(right->val);
            prev = right;
            right = right->next;
            if (nh == NULL) {
                nh = nn;
                temp = nn;
            } else {
                temp->next = nn;
                temp = temp->next;
            }
            delete prev;
        }
        return nh;
    }
};
