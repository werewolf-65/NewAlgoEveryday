#include "check_bst.h"
#include <stdlib.h>
#include "limits.h"


// int is_binary_search_tree(struct BstNode* root){
// 	if(root==NULL) return 1 ;
// 	if(is_subtree_lesser(root->left,root->data)
// 	&& is_subtree_greater(root->right,root->data)
// 	&& is_binary_search_tree(root->left)
// 	&& is_binary_search_tree(root->right))
// 		return 1;
// 	else
// 		return 0;
// }
int is_binary_search_tree(struct BstNode* root){
	return is_bst_util(root,INT_MIN,INT_MAX);
}

int is_subtree_lesser(struct BstNode* root,int value){
	if(root==NULL) return 1;
	if(root->data <= value && is_subtree_lesser(root->left,value) 
	   && is_subtree_lesser(root->right,value))
		return 1;
	else
		return 0;
}
int is_subtree_greater(struct BstNode* root,int value){
	if(root==NULL) return 1;
	if(root->data >= value && is_subtree_greater(root->left,value) 
	   && is_subtree_greater(root->right,value))
		return 1;
	else
		return 0;
}

int is_bst_util(struct BstNode* root,int min_val,int max_val){
/* sets the range */
	if(root==NULL){
		return 1;
	}
	if((root->data >=min_val) && (root->data<=max_val) && 
	is_bst_util(root->left,min_val,root->data)&&
	is_bst_util(root->right,root->data,max_val)){
		return 1;
	 }
	else{
		return 0;
	}
}
