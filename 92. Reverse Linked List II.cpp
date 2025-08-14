Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
  
Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]




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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head; int i = 1;
        stack <int> s;
        while(temp->next != NULL && i < left){
            temp = temp -> next; i++;
        }
        ListNode* curr = temp;
        while (curr && i <= right){
            s.push(curr->val);
            curr = curr -> next; i++;
        }
        while (!s.empty() && left <= right){
            temp -> val = s.top(); 
            temp = temp -> next;
            s.pop(); 
            left++; 
        }
        return head;
    }
};
