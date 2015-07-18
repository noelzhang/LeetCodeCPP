class Solution {
private:
	unordered_map<TreeNode*, int> depth;
	unordered_map<TreeNode*, TreeNode*> parents;
	void DFS(TreeNode * root,int d){
		if(root->left){
			depth[root->left]=d+1;
			parents[root->left]=root;
			DFS(root->left,d+1);
		}
		if(root->right){
			depth[root->right]=d+1;
			parents[root->right]=root;
			DFS(root->right,d+1);
		}
	}
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        depth[root]=0;
        parents[root]=NULL;
        DFS(root,0);
        while(1){
        	if(p==q)
        		return p;
        	if(depth[p]<depth[q])
        		q=parents[q];
        	else if(depth[p]>depth[q])
        		p=parents[p];
        	else{
        		q=parents[q];
        		p=parents[p];
        	}
        }
    }
};
