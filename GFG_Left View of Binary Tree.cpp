
Solved
Difficulty: EasyAccuracy: 33.74%Submissions: 612K+Points: 2Average Time: 20m
Given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

Note: If the tree is empty, return an empty list.

Examples :

Input: root = [1, 2, 3, 4, 5, N, N]

Output:[1, 2, 4]
Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.

Input: root = [1, 2, 3, N, N, 4, N, N, 5, N, N]

Output: [1, 2, 4, 5]
Explanation: From the left side of the tree, only the nodes 1, 2, 4, and 5 are visible.

Constraints:
0 ≤ number of nodes ≤ 105
0 ≤ node -> data ≤ 105





/*
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};
*/

class Solution {
	public:
	vector<int> leftView(Node *root) {
		// code here
		if (!root)  return {};
		vector<int>ans;
		queue<Node*>q;
		Node* temp = root;
		q.push(temp);
		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i<size; ++i) {
				temp = q.front();
				q.pop();
				if(0==i) ans.push_back(temp->data);
				if (temp->left)
					q.push(temp->left);
				if (temp->right)
					q.push(temp->right);
			}
		}
		return ans;
	}
};
