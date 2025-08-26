Given a matrix mat[][] of size n*n, where each row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Examples:
Input: mat[][] = [[16, 28, 60, 64], k = 3
                [22, 41, 63, 91],
                [27, 50, 87, 93],
                [36, 78, 87, 94]]
Output: 27
Explanation: 27 is the 3rd smallest element.
Input: mat[][] = [[10, 20, 30, 40], k = 7
                [15, 25, 35, 45],
                [24, 29, 37, 48],
                [32, 33, 39, 50]] 
Output: 30
Explanation: 30 is the 7th smallest element.




optimised approach
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        vector<pair<int,pair<int,int>>> v;
        for (int i = 0; i<mat.size(); i++){
            v.push_back({mat[i][0], {i,0} });
        }
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> >pq(v.begin(), v.end());
        pair<int,pair<int,int>> Element;
        while(k>1){
            Element = pq.top();
            pq.pop();
            int i = Element.second.first;    
            int j = Element.second.second;
            if (j+1 < mat[0].size()) {pq.push({mat[i][++j], {i,j} });}
            k--;
        }
        return pq.top().first;
    }
};
