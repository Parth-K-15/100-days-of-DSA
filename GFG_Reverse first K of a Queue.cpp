Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

"If the size of queue is smaller than the given k , then return the original queue."

Examples:

Input: q = [1, 2, 3, 4, 5], k = 3
Output: [3, 2, 1, 4, 5]
Explanation: After reversing the first 3 elements from the given queue the resultant queue will be 3 2 1 4 5
Input: q = [4, 3, 2, 1], k = 4
Output: [1, 2, 3, 4] 
Explanation: After reversing the first 4 elements from the given queue the resultant queue will be 1 2 3 4 


  // Not accepted due to time complex.
class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        stack <int> s;
        int i = 0;
        vector <int> v(0);
        while(!q.empty()){
            if (i < k){
                s.push(q.front());
                i++;
            }
            else{
                v.push_back(q.front());
            }
            q.pop();
        }
        while (!s.empty()){
            q.push(s.top());
        }
        while (!v.empty()){
            q.push(v.front());
        }
        return q;
    }
};


// optimised
class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if (k > q.size() || k < 0) {
            return q;
        }
        stack <int> s;
        int i = 0;
        int num = q.size()-k;
        while(!q.empty() && i < k){
            s.push(q.front());
            q.pop();
            i++;
        }
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        for (int j =0; j<num; j++){
            q.push(q.front());
            q.pop();
        }
        return q;
    }
};
