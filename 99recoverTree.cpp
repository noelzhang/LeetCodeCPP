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
	TreeNode * first;
	TreeNode * second;
	vector<TreeNode *> list;
	void mid(TreeNode * root){
		if(root ->left)
			mid(root->left);
		list.push_back(root);
		if(root -> right)
			mid(root -> right);
	}
public:
    void recoverTree(TreeNode* root) {
        first = second = nullptr;
        mid(root);
        for(auto itr = list.begin(); itr != prev(list.end()); ++itr){
        	if((*itr)->val > (*next(itr))->val){
        		if(first == nullptr){
        			first = *itr;
        		}
        		second = *next(itr);
        	}
        }
        swap(first->val,second->val);
    }
};