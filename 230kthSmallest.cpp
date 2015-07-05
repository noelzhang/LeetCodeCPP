/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
public:
    int kthSmallest(TreeNode* root, int k) {
        auto cur = root;
        stack<TreeNode*> s;
        while(cur){
        	s.push(cur);
        	cur = cur ->left;
        }
        for (int j = 0; j < k; ++j)
        {
        	cur = s.top()
        	ans = cur->val;
        	s.pop();
        	if(cur->right){
        		cur=cur->right;
        		while(cur){
        			s.push(cur);
        			cur=cur->left;
        		}
        	}
        }
        return ans;
    }
};