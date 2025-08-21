Given a Binary Heap of size n in an array arr[]. Write a program to calculate the height of the Heap.

Note: Return 1 if the n is 1.

Examples:

Input: n = 6, arr[] = [1, 3, 6, 5, 9, 8]
Output: 2
Explaination: The tree is like the following
        (1)
       /   \
    (3)    (6)
    / \     /
  (5) (9) (8)

Input: n = 9, arr[] = [3, 6, 9, 2, 15, 10, 14, 5, 12]
Output: 3
Explaination: The tree looks like following
           (2)
        /      \
      (3)      (9)
     /  \     /   \
   (5) (15) (10) (14)
   / \
 (6) (12)





class Solution {
  public:
    int heapHeight(int n, int arr[]) {
        // code here
        if (n==1) return 1;
        int height = 0;
        while(n>1){
            n = n/2;
            height++;
        }
        return height;
    }
};
