Given an array arr[] of n sorted linked lists of different sizes. Your task is to merge all these lists into a single sorted linked list and return the head of the merged list.

Examples:

Input:
   
Output: 1 -> 2 -> 3 -> 4 -> 7 -> 8 -> 9
Explanation: The arr[] has 3 sorted linked list of size 3, 3, 1.
1st list: 1 -> 3 -> 7
2nd list: 2 -> 4 -> 8
3rd list: 9
The merged list will be: 
    
Input:
   
Output: 1 -> 3 -> 4 -> 5 -> 6 -> 8
Explanation: The arr[] has 3 sorted linked list of size 2, 1, 3.
1st list: 1 -> 3
2nd list: 8
3rd list: 4 -> 5 -> 6
The merged list will be: 






/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

struct compare{
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code herea
        priority_queue<Node*, vector<Node*>, compare>pq(arr.begin(),arr.end());
        Node * dummy = new Node(0);
        Node* d = dummy;
        Node *temp;
        while(!pq.empty()){
            temp = pq.top();
            pq.pop();
            if(temp->next) pq.push(temp->next);
            d -> next = temp;
            d = temp;
        }
        d = dummy->next;
        delete dummy;
        return d;
    }
};
