#ifndef CHECK_BST_H
#define CHECK_BST_H
struct BstNode{
	int data;
	struct BstNode* left;
	struct BstNode* right;
};
int is_binary_search_tree(struct BstNode* root);
int is_subtree_lesser(struct BstNode* root,int value);
int is_subtree_greater(struct BstNode* root,int value);
int is_bst_util(struct BstNode* root,int min_val,int max_val);

#endif 
