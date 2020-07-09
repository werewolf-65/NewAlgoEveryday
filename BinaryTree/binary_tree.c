#include <stdio.h> 
#include <stdlib.h> 
#include "./check_bst.h"
// struct BstNode{
// 	int data;
// 	struct BstNode* left;
// 	struct BstNode* right;
// };

struct BstNode* get_new_node(int data){
	struct BstNode* new_node=(struct BstNode*)malloc(sizeof(struct BstNode));
	new_node->data=data;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}

struct BstNode* insert(struct BstNode* root, int data){
	if(root==NULL){
		root=get_new_node(data);
	}
	else if(data<=root->data){
		root->left=insert(root->left,data);
	}
	else{
		root->right=insert(root->right,data);
	}
	return root;
}

int search(struct BstNode* root,int data){
	if(root==NULL){
		return 0;
	}
	if(root->data == data){
		return 1;
	}
	else if(data<=root->data){
		return search(root->left,data);
	}
	else{
		return search(root->right,data);
	}
}

//find the min element of the tree 
int find_min(struct BstNode* root){
	if(root==NULL){
		printf("Error:Empty tree\n");;
		return -1;
	}
	if(root->left ==NULL){
		return root->data;
	}
	else{
		return find_min(root->left);
	}
}
//find the max element of the tree 
int find_max(struct BstNode* root){
	if(root==NULL){
		printf("Empty tree error\n");
		return -1;
	}
	if(root->right==NULL){
		return root->data;
	}
	else{
		return find_max(root->right);
	}
}

int max(int a,int b){
	int ret;
	ret=(a>b)?a:b;
	return ret;

}
//find the height of the tree 
int find_height(struct BstNode* root){
	if (root==NULL)
		return -1; 
	return max(find_height(root->left),find_height(root->right))+1;
	//calculate heights of left and right subtrees recursively 
}

void preorder(struct BstNode* root){
	if(root==NULL) return;
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(struct BstNode* root){
	if(root==NULL) return;
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}
void postorder(struct BstNode* root){
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->data);
}


int main(){
	struct BstNode* root_ptr;
	int data;
	root_ptr=NULL;
	root_ptr=insert(root_ptr,8);
	root_ptr=insert(root_ptr,10);
	root_ptr=insert(root_ptr,7);
	root_ptr=insert(root_ptr,11);
	root_ptr=insert(root_ptr,9);

	printf("Enter a number to search:\n");
	scanf("%d",&data);
	search(root_ptr,data)?printf("Found"):printf("Not found\n");
	printf("Minimum element:%d\n",find_min(root_ptr));
	printf("Maximum element:%d\n",find_max(root_ptr));
	
	printf("Height of the tree is:%d\n",find_height(root_ptr));
	is_binary_search_tree(root_ptr)?printf("It is a BST\n"):printf("Not a BST\n");
	
	printf("Preorder:\n");
	preorder(root_ptr);
	
	printf("\nPostorder:\n");
	postorder(root_ptr);
	
	printf("\nInorder:\n");
	inorder(root_ptr);

	return 0;
}
