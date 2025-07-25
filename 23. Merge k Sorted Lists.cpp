You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []



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

TC:O(N logN)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp) {
                v.push_back(temp->val);
                ListNode* del = temp;
                temp = temp->next;
                delete del;
            }
        }
        if (v.empty()) return nullptr;
        sort(v.begin(), v.end());
        ListNode* dummy = new ListNode(v[0]);
        ListNode* d = dummy;
        for (int i = 1; i < v.size(); i++) {
            ListNode* nn = new ListNode(v[i]);
            d->next = nn;
            d = d->next;
        }
        return dummy;
    }
};



// OR


TC:O(N logN) in worst case
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, int> m;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp) {
                m[temp->val]++;
                ListNode* del = temp;
                temp = temp->next;
                delete del;
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* d = dummy;
        for (auto it = m.begin(); it != m.end(); it++) {
            while (it->second--) {
                ListNode* nn = new ListNode(it->first);
                d->next = nn;
                d = d->next;
            }
        }
        d = dummy;
        dummy = dummy->next;
        delete d;
        return dummy;
    }
};
