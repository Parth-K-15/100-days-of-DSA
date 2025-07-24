You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.


Input: head = [1,2,3,4]
Output: [1,4,2,3]
  
Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]




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
    void reorderList(ListNode* head) {
        vector<ListNode*>v;
        ListNode* temp = head;
        while(temp){
            v.push_back(temp);
            temp = temp->next;
        }
        int n = v.size();
        int i = 0;
        while(i<n/2){
            v[i]->next = v[n-1-i];
            v[n-1-i]->next = v[i+1];
            i++;
        }
        v[i]->next = NULL;        
    }
};
