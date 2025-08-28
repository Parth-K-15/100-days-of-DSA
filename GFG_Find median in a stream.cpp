Given a data stream arr[] where integers are read sequentially, the task is to determine the median of the elements encountered so far after each new integer is read.

There are two cases for median on the basis of data set size.

1. If the data set has an odd number then the middle one will be consider as median.
2. If the data set has an even number then there is no distinct middle value and the median will be the arithmetic mean of the two middle values.

Examples:
Input:  arr[] = [5, 15, 1, 3, 2, 8]
Output: [5.0, 10.0, 5.0, 4.0, 3.0, 4.0] 
Explanation: 
After reading 1st element of stream – 5 -> median = 5.0
After reading 2nd element of stream – 5, 15 -> median = (5+15)/2 = 10.0 
After reading 3rd element of stream – 5, 15, 1 -> median = 5.0
After reading 4th element of stream – 5, 15, 1, 3 ->  median = (3+5)/2 = 4.0
After reading 5th element of stream – 5, 15, 1, 3, 2 -> median = 3.0
After reading 6th element of stream – 5, 15, 1, 3, 2, 8 ->  median = (3+5)/2 = 4.0
Input: arr[] = [2, 2, 2, 2]
Output: [2.0, 2.0, 2.0, 2.0]
Explanation: 
After reading 1st element of stream – 2 -> median = 2.0
After reading 2nd element of stream – 2, 2 -> median = (2+2)/2 = 2.0
After reading 3rd element of stream – 2, 2, 2 -> median = 2.0
After reading 4th element of stream – 2, 2, 2, 2 ->  median = (2+2)/2 = 2.0







class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        int n = arr.size();
        priority_queue<int>left;
        priority_queue<int, vector<int>, greater<int>>right;
        left.push(arr[0]);
        vector<double> ans = {arr[0]};
        
        for (int i = 1; i<n;i++){
            int x = arr[i];
            if (x <= left.top()){
                left.push(x);
            } else{
                right.push(x);
            }
            if (left.size()-2 == right.size()){
                right.push(left.top());
                left.pop();
            }
            else if (left.size() == right.size()-2){
                left.push(right.top());
                right.pop();
            }
            if (left.size() == right.size()){
                ans.push_back((left.top() + right.top())/2.0);
            }
            else if (left.size()-1 == right.size()){
                ans.push_back(left.top());
            }
            else if (left.size() == right.size()-1){
                ans.push_back(right.top());
            }
        }
        return ans;
    }
};
