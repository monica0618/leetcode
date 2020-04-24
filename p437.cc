#include "bits/stdc++.h"
using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
 } ();

//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int lead(TreeNode* root, int sum) {
  if(root == nullptr) return 0;
  return(root->val == sum) + lead(root->left, sum - root->val) + lead(root->right, sum - root->val);
}

class Solution {
public:
  int pathSum(TreeNode* root, int sum) {
    if (root == nullptr) return 0;
    return lead(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
  }
};

