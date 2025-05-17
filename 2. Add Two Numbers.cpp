// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.


// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]

// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]



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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        string s1 = "";
        while(temp1 != NULL){
            s1 = to_string(temp1 -> val) + s1;
            temp1 = temp1->next;
        }

        ListNode* temp2 = l2;
        string s2 = "";
        while(temp2 != NULL){
            s2 = to_string(temp2 -> val) + s2;
            temp2 = temp2->next;
        }

        int num1 = stoi(s1);
        int num2 = stoi(s2);
        int sum = num1+num2;
        string s3 = to_string(sum);
        //can't use stoi for char
        //hence use 'char' - '0' => ascii value substraction
        ListNode* l3 = new ListNode(s3[s3.size()-1] - '0');
        ListNode* temp3 = l3;
        for (int i = s3.size()-2; i>=0; --i){
            temp3->next = new ListNode(s3[i]-'0');
            temp3 = temp3->next;
        }
        return l3;
    }
};





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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* temp = new ListNode(0);
        ListNode* cn = temp;
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry != 0){
            int sum = carry;

            if (l1 != NULL){
                sum += l1->val;
                l1 = l1 -> next;
            }
            if (l2 != NULL){
                sum += l2->val;
                l2 = l2 -> next;
            }
            carry = sum / 10;       // Update carry (1 if sum >= 10, else 0)
            cn -> next = new ListNode(sum % 10);
            cn = cn->next;
        }
        return temp->next;      //ignore 0
    }
};
